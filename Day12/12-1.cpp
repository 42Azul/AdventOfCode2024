#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> matrix;

vector<vector<bool>> visited;



bool isCharAt(int x, int y, char regChar){
    return(x >=0 && y >=0 && y < matrix.size() && x < matrix[0].size() && matrix[y][x] == regChar);
}


vector<pair<long, long>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};


pair<long, long> exploreRegion(int x, int y, char regChar){
    //cout << "Exploring region at (" << x << ", " << y << ") with character: " << regChar << endl;
    if(!isCharAt(x, y, regChar) || visited[y][x] == true ) return make_pair(0, 0);
    visited[y][x] = true;
    long totalArea = 0;
    long totalPerimeter = 0;
    for(pair<long,long> dir: directions){
        long newX = x + dir.first;
        long newY = y + dir.second;
        pair<long, long> areaAndPerimeter = exploreRegion(newX, newY, regChar);
        totalArea += areaAndPerimeter.first;
        totalPerimeter +=  areaAndPerimeter.second + (!isCharAt(newX, newY, regChar));
    }
      
    return make_pair(totalArea +1, totalPerimeter);
}


int main(){
    string line;
    while(getline(cin, line)){
        istringstream iss(line);
        char character;
        vector<char> row;
        vector<bool> rowFalse;
        while(iss >> character){
            row.push_back(character);
            rowFalse.push_back(false); 
        }
        matrix.push_back(row);
        visited.push_back(rowFalse);  // Initialize visited matrix with false values.
    }

    cout << "Sizes of matrix are: " << matrix.size() << endl;
    long x = 0;
    long y = 0;
    long total = 0;
    while(y < matrix.size()){
        if(visited[y][x] == false){
            pair<long, long> areaPerimeter = exploreRegion(x, y, matrix[y][x]);
            cout << "Area: " << areaPerimeter.first << ", Perimeter: " << areaPerimeter.second << " Total: " << areaPerimeter.first * areaPerimeter.second << " For character: " << matrix[y][x] << endl;
            total += areaPerimeter.first * areaPerimeter.second;
        }
        x++;
        if(x == matrix[0].size()){
            y++;
            x = 0;
        }
    }
    cout << total << endl;


}