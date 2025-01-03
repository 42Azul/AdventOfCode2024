#include<bits/stdc++.h>
using namespace std;


bool searchCharInPosition(int x, int y, vector<vector<char>>& xmasPuzzle, char expectedChar) {
    bool toReturn =  x >=0 && y >=0 && xmasPuzzle.size() > y && xmasPuzzle[0].size() > x  && xmasPuzzle[y][x]==expectedChar;
    return toReturn;
}

bool searchXmasInCross(int x, int y, vector<vector<char>>& xmasPuzzle) {
    bool isXmasPuzzleFoundMASFront = searchCharInPosition(x-1, y-1, xmasPuzzle, 'M') && searchCharInPosition(x+1, y+1, xmasPuzzle, 'S');
    bool isXmasPuzzleFoundSAMFront = searchCharInPosition(x-1, y-1, xmasPuzzle, 'S') && searchCharInPosition(x+1, y+1, xmasPuzzle, 'M');

    bool isXmasPuzzleFoundSAMBack = searchCharInPosition(x+1, y-1, xmasPuzzle, 'S') && searchCharInPosition(x-1, y+1, xmasPuzzle, 'M');
    bool isXmasPuzzleFoundMASBack = searchCharInPosition(x+1, y-1, xmasPuzzle, 'M') && searchCharInPosition(x-1, y+1, xmasPuzzle, 'S');

    return (isXmasPuzzleFoundMASFront || isXmasPuzzleFoundSAMFront) && (isXmasPuzzleFoundSAMBack || isXmasPuzzleFoundMASBack);
}


int main() {


    vector<vector<char>> xmasPuzzle;
    long count = 0;

    // Read the dimensions of the Xmas puzzle
    string line;
    // Read the input values
    while(getline(cin, line)) {
        vector<char> row;
        for(char c : line) {
            row.push_back(c);
        }
        xmasPuzzle.push_back(row);
    }

    for(int x = 0; x < xmasPuzzle[0].size(); x++) {
        for(int y = 0; y < xmasPuzzle.size(); y++) {
            if(xmasPuzzle[y][x] == 'A'){
                count += searchXmasInCross(x, y, xmasPuzzle);
            }
        }
    }
    cout << count << endl;

    return 0;
}




