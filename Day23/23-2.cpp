#include <bits/stdc++.h>
using namespace std;


int NUM_OF_CHARS = 'z'- 'a' + 1;


int fromString(string str){
    char firstChar = str[0];
    return (firstChar - 'a')*(NUM_OF_CHARS) + str[1] - 'a';
}

string toString(int charValue){
    char firstChar = 'a' + charValue/NUM_OF_CHARS;
    char secondChar = 'a' + charValue % NUM_OF_CHARS;
    return {firstChar, secondChar};
}

map<int, list<int>> adjacencyList;

void addEdge(int a, int b){
    adjacencyList[a].push_back(b);
    adjacencyList[b].push_back(a);
}


set<int> getMaximalFullyConnected(int startingNode){
    unordered_set<int> visited;
    set<int> connected;
    queue<int> bfsQueue;
    bfsQueue.push(startingNode);
    visited.insert(startingNode);
    connected.insert(startingNode);
    while(!bfsQueue.empty()){
        int currentNode = bfsQueue.front();
        bfsQueue.pop();
        for(int neighbor: adjacencyList[currentNode]){
            if(visited.find(neighbor) == visited.end()){
                visited.insert(neighbor);
                list<int> neighborNeighbors = adjacencyList[neighbor];
                bool isConnectedToAll = true;
                for(int inMaximal : connected){
                    if(find(neighborNeighbors.begin(), neighborNeighbors.end(), inMaximal) == neighborNeighbors.end()){
                        isConnectedToAll = false;
                        break;
                    }

                }
                if(isConnectedToAll){
                    cout << "Connected to " << neighbor << endl;
                    connected.insert(neighbor);
                    bfsQueue.push(neighbor);
                }
                
            }
        }
    }
    return connected;
}
    



int main(){
    char a, b;
    string first, second;

    while(getline(cin, first, '-') && getline(cin, second)){
        int firstValue = fromString(first);
        int secondValue = fromString(second);
        addEdge(firstValue, secondValue);
    }

    long total = 0;


    set<int> maxMaximalConnected;
    set<int> currentMaximalConnected;
    int maxSize = 0;
    for(auto mappedInt: adjacencyList){
        int node = mappedInt.first;
        currentMaximalConnected = getMaximalFullyConnected(node);
        cout << "Current maximal connected: " << currentMaximalConnected.size() << endl;
        cout << "Current maximal is bigger than " << maxSize << " with boolean  " << (currentMaximalConnected.size() > maxSize) << endl;
        if(currentMaximalConnected.size() > maxSize){
            maxSize = currentMaximalConnected.size();
            cout << "Maximal connection " << currentMaximalConnected.size() << endl;
            maxMaximalConnected = currentMaximalConnected;
        }
    }

    //Print the biggest one alphabetically ordered, so we order the set by int
    for(int node: maxMaximalConnected){
        cout << toString(node) << ",";
    }
    cout << endl;

    return 0;

}


