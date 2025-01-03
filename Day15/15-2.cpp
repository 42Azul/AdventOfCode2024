#include<bits/stdc++.h>


#include <chrono>
#include <thread>

using namespace std;

namespace std{
    std::pair<int,int> operator+(const std::pair<int,int> & l,const std::pair<int,int> & r) {   
        return {l.first+r.first,l.second+r.second};                                    
    }    
}


vector<vector<char>> world;



void printWorld(){
    for(auto row:  world){
        for(char c: row){
            cout << c;
        }
        cout << endl;
    }
    this_thread::sleep_for(std::chrono::milliseconds(100));


}

pair<int, int> UP = {0, -1};
pair<int, int> DOWN = {0, 1};

map<char, pair<int, int>> directions = {{'>',{1,0}}, { '<', {-1, 0}}, { '^', UP}, {'v', DOWN}};

bool canMove(pair<int, int> position, pair<int, int> direction, bool isPartnerBox){
    char actualBlock = world[position.second][position.first];
    cout << "Actual block: " << actualBlock << " at position x: " << position.first << " y: " << position.second << endl;
    if(actualBlock=='#') return false;
    if(actualBlock == '.') return true;
    bool movable = canMove(position + direction, direction, false);

    if(isPartnerBox==false && actualBlock == '[' && (direction == UP || direction == DOWN) ) movable = movable && canMove(position + directions['>'], direction, true);
    else if(isPartnerBox==false && actualBlock == ']' && (direction == UP || direction == DOWN) ) movable = movable &&  canMove(position + directions['<'], direction, true);

    return movable;
}

void move(pair<int, int> position, pair<int, int> direction, bool isPartnerBox){
    char actualBlock = world[position.second][position.first];
    if(actualBlock == '.') return;
    pair<int, int> newPosition = position + direction;
    move(newPosition, direction, false);
    
    if(isPartnerBox==false && actualBlock == '[' && (direction == UP || direction == DOWN) ) move(position + directions['>'], direction, true);
    else if(isPartnerBox==false && actualBlock == ']' && (direction == UP || direction == DOWN) ) move(position + directions['<'], direction, true);

    world[newPosition.second][newPosition.first] = actualBlock;
    world[position.second][position.first] = '.';
}


int main(){
    string line;
    pair<int, int> startingPos;
    while(getline(cin, line) && line.size() > 2){
        vector<char> row;
        istringstream is(line);
        char c;
        while(is >> c){
            switch (c){
                case '@':
                    startingPos = {row.size(), world.size()};
                    row.push_back(c);
                    row.push_back('.');
                    break;
                case 'O':
                    row.push_back('[');
                    row.push_back(']');
                    break;
                default:
                    row.push_back(c);
                    row.push_back(c);
                    break;
            }
        }
        world.push_back(row);
    }


    //Example print the world
    for(auto & row : world){
        for(auto & c : row){
            cout << c;
        }
        cout << endl;
    }
    cout << endl;


    char inputChar;
    while(cin>>inputChar){
        pair<int, int> direction = directions[inputChar];
        if(canMove(startingPos, direction, false)){
            move(startingPos, direction, false);
            startingPos = startingPos + direction;
        }
        // printWorld();
        // cout << "Current position: (" << startingPos.first << ", " << startingPos.second << ")" << endl;
        // cout << "Direction: (" << direction.first << ", " << direction.second << ")" << endl;
        // cout << "--------------------" << endl;
    }


    long total = 0;
    long x, y = 0;
    while(y < world.size()){
        x = 0;
        while(x < world[0].size()){
            if(world[y][x] == '['){
                //cout << "Position of the box is: ( " << x << " " << y << " )" << endl;
                total += y*100 + x;
            }
            x++;
        }
        y++;
    }

    cout << total << endl;

    




}