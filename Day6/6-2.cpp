#include <bits/stdc++.h>
#include <tuple>
#include <unordered_set>
using namespace std;


struct State {
    int x, y;
    int dx, dy;

    bool operator==(const State& other) const {
        return x == other.x && y == other.y && dx == other.dx && dy == other.dy;
    }
};

struct StateHash {
    size_t operator()(const State& s) const {
        auto h1 = std::hash<long long>()(((long long)s.x << 32) ^ s.y);
        auto h2 = std::hash<long long>()(((long long)s.dx << 32) ^ s.dy);
        return h1 ^ (h2 + 0x9e3779b97f4a7c15ULL + (h1 << 6) + (h1 >> 2));
    }
};



void printMap(vector<vector<int>>& map){
    for(int i = 0; i < map.size(); i++){
        for(int j = 0; j < map[i].size(); j++){
            if (map[i][j] > 0) cout << "■";
            else map[i][j] == -1? cout << "#": cout << "_";
        }
        cout << endl;
    }
}

void rotate(long &dx, long &dy){
    long temp = dx;
    dx = -dy;
    dy = temp;
}

bool isLoop(vector<vector<int>> &map, int x, int y, pair<int, int> direction){
    unordered_set<State, StateHash> visitedCells;
    long dx = direction.first, dy = direction.second;
    while(x >= 0 && y >= 0 && x < map.size() && y < map[0].size()){
        if(map[y][x] == -1){
            x -= dx, y -= dy;
            rotate(dx, dy);
        }
        State current { x, y, (int)dx, (int)dy };
        if (visitedCells.find(current) != visitedCells.end()) {
            return true;
        }
        visitedCells.insert(current);
        x += dx, y += dy;

    }
    return false;
}





int main() {

    string line;
    vector<vector<int> > map;
    long x, y, startX, startY;

    while(getline(cin, line)){
        istringstream iss(line);
        vector<int> row;
        char c;
        while(iss >>  c){
            row.push_back(-1*(c == '#'));
            if(c == '^'){
                startX = row.size()  - 1;
                startY = map.size();
            }
        }
        map.push_back(row);
    }

    long dx = 0, dy = -1;
    x = startX;
    y = startY;
    long long count = 0;

    vector<tuple<pair<long,long>, pair<long, long> , pair<long, long>>> visited;

    long prevX = startX, prevY = startY;
    long prevDx = dx, prevDy = dy;
    while(x < map[0].size() && y < map.size() && x>=0 && y>=0){
        if(map[y][x] == -1){
            y = y - dy;
            x = x - dx;
            rotate(dx, dy);
        } else {
        if (map[y][x] == 0 && (x!=startX || y!=startY)){
            map[y][x] = 1;
            visited.push_back(make_tuple(make_pair(x, y), make_pair(dx, dy), make_pair(prevX, prevY)));
        }
        prevX = x;
        prevY = y;
        prevDx = dx;
        prevDy = dy;
        }
        
        x += dx;
        y += dy;
    }


    for(tuple<pair<long, long>, pair<long, long>, pair<long, long>> p : visited){
        pair<long, long> position = get<0>(p);
        pair<long, long> direction = get<1>(p);
        pair<long, long> previousPosition = get<2>(p);
        map[position.second][position.first] = -1;
        if(isLoop(map, previousPosition.first, previousPosition.second, direction)){
            //cout << "Loop at: (" << position.first << "," << position.second << ")" << endl;
            count++;
        }
        else {
            //cout << "No loop at: (" << p.first << ", " << p.second << ")" << endl;
        }
        
        map[position.second][position.first] = 0;
    }
    cout << count << endl;

    return 0;


}