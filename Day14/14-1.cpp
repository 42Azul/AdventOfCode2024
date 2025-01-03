#include <bits/stdc++.h>
using namespace std;

// long WIDTH = 11;
// long HEIGHT = 7;


long WIDTH = 101;
long HEIGHT = 103;

long HALF_WIDTH = WIDTH/2;
long HALF_HEIGHT = HEIGHT/2;


vector<long> quadrantsTotal = {0,0,0,0};


void addToQuadrant(pair<long,long> position){
    long x = position.first;
    long y = position.second;

    if(x > HALF_WIDTH && y > HALF_HEIGHT) quadrantsTotal[3]++;
    else if(x > HALF_WIDTH && y < HALF_HEIGHT) quadrantsTotal[2]++;
    else if(x < HALF_WIDTH && y > HALF_HEIGHT) quadrantsTotal[1]++;
    else if(x < HALF_WIDTH && y < HALF_HEIGHT) quadrantsTotal[0]++;
}


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


int main(){
    string line;
    while(getline(cin, line)){
        pair<pair<long, long>, pair<long, long>> processedInput =  processInput(line);
        long speedX = processedInput.second.first;
        if(speedX < 0){
            speedX = (speedX%WIDTH) + WIDTH;
        }
        long speedY = processedInput.second.second;
        if(speedY < 0){
            speedY = (speedY%HEIGHT) + HEIGHT;
        }


        long newX = (processedInput.first.first + speedX*100)%WIDTH; 
        long newY = (processedInput.first.second + speedY*100)%HEIGHT;
        cout << newX << " " << newY << endl;
        addToQuadrant({newX, newY});
    }

    long total = 1;
    for(long quadrantSum : quadrantsTotal){
        cout << quadrantSum << endl;
        total *= quadrantSum;
    }
    cout << total << endl;

    return 0;
}