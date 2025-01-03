#include<bits/stdc++.h>
using namespace std;


bool searchCharInDirection(int x, int y, int dx, int dy, vector<vector<char>>& xmasPuzzle, char expectedChar) {
    int newX = x + dx;
    int newY = y + dy;
    return newX >= 0 && newX < xmasPuzzle[0].size() && newY >= 0 && newY < xmasPuzzle.size() && xmasPuzzle[newY][newX] == expectedChar;
}

bool searchXmasInDirectionWithX(int x, int y, int dx, int dy, vector<vector<char>>& xmasPuzzle) {
    bool isXmasPuzzleFound = true;
    isXmasPuzzleFound = isXmasPuzzleFound && searchCharInDirection(x, y, dx, dy, xmasPuzzle, 'M');
    isXmasPuzzleFound = isXmasPuzzleFound && searchCharInDirection(x, y, 2*dx, 2*dy, xmasPuzzle, 'A');
    isXmasPuzzleFound = isXmasPuzzleFound && searchCharInDirection(x, y, 3*dx, 3*dy, xmasPuzzle, 'S');

    if(isXmasPuzzleFound){
        cout << "searchXmasInDirectionWithX : (" << x << "," << y << ") -> (" << (x+3*dx) << "," << (y+3*dy) << ")" << endl;
    }
    return isXmasPuzzleFound;
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

    // Let us code the solution here. The idea is to search for X or S in the table
    for(int y = 0; y < xmasPuzzle.size(); y++) {
        for(int x = 0; x < xmasPuzzle[0].size(); x++) {
            if(xmasPuzzle[y][x] == 'X'){
                // Search in advancing directions
                count +=  searchXmasInDirectionWithX(x, y, 1, 0, xmasPuzzle);
                count +=  searchXmasInDirectionWithX(x, y, 0, 1, xmasPuzzle);
                count +=  searchXmasInDirectionWithX(x, y, 1, 1, xmasPuzzle);
                count +=  searchXmasInDirectionWithX(x, y, 1, -1, xmasPuzzle);
                count +=  searchXmasInDirectionWithX(x, y, -1, 1, xmasPuzzle);
                count +=  searchXmasInDirectionWithX(x, y, -1, -1, xmasPuzzle);
                count +=  searchXmasInDirectionWithX(x, y, 0, -1, xmasPuzzle);
                count +=  searchXmasInDirectionWithX(x, y, -1, 0, xmasPuzzle);
            }
        }
    }
    cout << count << endl;

    return 0;
}




