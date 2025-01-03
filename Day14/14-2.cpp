#include <bits/stdc++.h>
using namespace std;

// long WIDTH = 11;
// long HEIGHT = 7;


long WIDTH = 101;
long HEIGHT = 103;

long HALF_WIDTH = WIDTH/2;
long HALF_HEIGHT = HEIGHT/2;


pair<pair<long, long>, pair<long,long>> processInput(string input){
    istringstream is(input);
    is.ignore(2);
    long x, y;
    is >> x;
    is.ignore(1);
    is >> y;

    is.ignore(3);
    long speedX, speedY;
    is >> speedX;
    is.ignore(1);
    is >> speedY;
    return {{x, y}, {speedX, speedY}};
}


void printMap(map<pair<long,long>, bool> position){
    for(long y = 0; y < HEIGHT; y++){
        for(long x = 0; x < WIDTH; x++){
            if(position[{x, y}]) cout << "■";
            else cout << " ";
        }
        cout << endl;
    }
    cout << endl;
}


int main(){
    string line;
    vector<pair<pair<long,long>, pair<long, long>>> robots;
    while(getline(cin, line) && line.size() > 2){
        pair<pair<long, long>, pair<long, long>> processedInput =  processInput(line);
        long speedX = processedInput.second.first;
        if(speedX < 0){
            speedX = (speedX%WIDTH) + WIDTH;
        }
        long speedY = processedInput.second.second;
        if(speedY < 0){
            speedY = (speedY%HEIGHT) + HEIGHT;
        }
        robots.push_back({processedInput.first, {speedX, speedY}});
    }
    long index = 0;
    bool isOverlap = false;
    while(isOverlap==true || getline(cin, line)){
        isOverlap = false;
        map<pair<long,long>, bool> position;
        for(pair<pair<long, long>, pair<long, long>> &robot : robots){
            long x = robot.first.first;
            long y = robot.first.second;
            long speedX = robot.second.first;
            long speedY = robot.second.second;

            x = (x + speedX)%WIDTH; 
            y = (y + speedY)%HEIGHT;
            if(position[{x, y}] == true){
                isOverlap = true;
            }
            position[{x, y}] = true;
            robot.first = {x, y};
            
        }
        index++;
        if(isOverlap == false){
            printMap(position);
            cout << "Map for index " << index << endl;
        }


    }

    return 0;
}