#include<bits/stdc++.h>
#include<queue>
#include<unordered_map>

using namespace std;

namespace std{
    pair<int, int> operator+(const pair<int, int> & a, const pair<int, int> & b) {
        return {a.first + b.first, a.second + b.second};
    }
}


long WIDTH = 70;
long HEIGHT = 70;


// long WIDTH = 6;
// long HEIGHT = 6;

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        // Hash the first element
        size_t hash1 = hash<T1>{}(p.first);
        // Hash the second element
        size_t hash2 = hash<T2>{}(p.second);
        // Combine the two hash values
        return hash1
               ^ (hash2 + 0x9e3779b9 + (hash1 << 6)
                  + (hash1 >> 2));
    }
};

unordered_map<pair<int, int>, bool, hash_pair> isBlock;

unordered_map<pair<int, int>, int, hash_pair> distances;

unordered_map<pair<int, int>, bool, hash_pair> isSeen;


vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};


bool comparePairs(const pair<int, pair<int, int>>& a, const pair<int,pair<int, int>>& b){ return a.first > b.first;};

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(&comparePairs)> minHeap(&comparePairs);


bool inRange(pair<int, int> a){
    return a.first >= 0 && a.first <= WIDTH && a.second >= 0 && a.second <= HEIGHT;
}



vector<pair<int, int>> getNeighbors(pair<int, int> position){
    vector<pair<int, int>> neighbors;
    for(pair<int, int> direction : directions) {
        if(inRange(position+direction) && !isBlock[position + direction]){
            neighbors.push_back(position+direction);
        }

    }
    return neighbors;
}



int main(){
    int i = 3035;
    pair<int, int> blockPosition;
    while(i--){
        cin>>blockPosition.first;
        cin.ignore();
        cin>>blockPosition.second;
        isBlock[blockPosition] = true;
    }

    minHeap.push({0, {0,0}});
    distances[{0,0}] = 0;
    while(!minHeap.empty()){
        pair<int, int> currentPosition = minHeap.top().second;
        minHeap.pop();
        if(isSeen[currentPosition]) continue;
        isSeen[currentPosition] = true;
        int currentDistance = distances[currentPosition];
        vector<pair<int, int>> neighbors = getNeighbors(currentPosition);
        cout << "Current position: " << currentPosition.first << " " << currentPosition.second << endl;
        for(pair<int, int> neighbor : neighbors){
            cout << "Neighbor : " << neighbor.first << " " << neighbor.second << endl;
            int neighborDistance = currentDistance + 1;
            int currentDistance = distances[neighbor];
            if(currentDistance == 0 || neighborDistance < distances[neighbor]){
                distances[neighbor] = neighborDistance;
                minHeap.push({neighborDistance, neighbor});
            }
        }
    }
    cout  << distances[{WIDTH, HEIGHT}] << endl;
}