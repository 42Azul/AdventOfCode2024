#include<bits/stdc++.h>
using namespace std;

namespace std{
    std::pair<int,int> operator+(const std::pair<int,int> & l,const std::pair<int,int> & r) {   
        return {l.first+r.first,l.second+r.second};                                    
    }    
}


vector<vector<char>> world;




map<char, pair<int, int>> directions = {{'>',{1,0}}, { '<', {-1, 0}}, { '^', {0, -1}}, {'v', {0, 1}}};

bool tryToMove(pair<int, int> position, pair<int, int> direction){
    char actualBlock = world[position.second][position.first];
    if(actualBlock=='#') return false;
    if(actualBlock == '.') return true;

    if(tryToMove(position + direction, direction)){
        pair<int, int> newPosition = position + direction;
        world[newPosition.second][newPosition.first] = actualBlock;
        world[position.second][position.first] = '.';
        cout << "Block at position " << position.first << " and " << position.second << " could be moved." << endl;
        return true;
    }
    return false;
}


int main(){
    string line;
    pair<int, int> startingPos;
    while(getline(cin, line) && line.size() > 2){
        vector<char> row;
        istringstream is(line);
        char c;
        while(is >> c){
            if(c == '@'){
                startingPos = {row.size(), world.size()};
            }
            row.push_back(c);
        }
        world.push_back(row);
    }

    long x, y = 0;
    while(y < world.size()){
        x = 0;
        while(x < world[0].size()){
            if(world[y][x] == 'O'){
                cout << "Position of the box is: ( " << x << " " << y << " )" << endl;
            }
            x++;
        }
        y++;
    }


    cout << " NOW WE PROCESS " << endl;
    char inputChar;
    while(cin>>inputChar){
        cout << "Processing " << inputChar << endl;
        if(tryToMove(startingPos, directions[inputChar])){
            startingPos = startingPos + directions[inputChar];
        }
    }


    long total = 0;
    y = 0;
    while(y < world.size()){
        x = 0;
        while(x < world[0].size()){
            if(world[y][x] == 'O'){
                cout << "Position of the box is: ( " << x << " " << y << " )" << endl;
                total += y*100 + x;
            }
            x++;
        }
        y++;
    }

    cout << total << endl;

    




}