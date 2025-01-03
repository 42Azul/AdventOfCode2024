#include <bits/stdc++.h>
using namespace std;


//TO BE IMPROVED WITH BOUNDARY SEARCH + CORNER COUNT WITH TRANSVERSE


namespace std{


std::pair<long,long> operator+(const std::pair<long,long> & l,const std::pair<long,long> & r) {   
    return {l.first+r.first,l.second+r.second};                                    
}    
}

vector<vector<char>> matrix;

vector<vector<bool>> visited;



bool isCharAt(pair<long, long> position, char regChar) {
    long x = position.first;
    long y = position.second;
    return(x >=0 && y >=0 && y < matrix.size() && x < matrix[0].size() && matrix[y][x] == regChar);
}

bool isCharAndUnvisited(pair<long, long> position, char regChar){
    return isCharAt(position, regChar) &&!visited[position.second][position.first];
}


pair<long, long> UP = {0, -1};
pair<long, long> DOWN = {0, 1};
pair<long, long> LEFT = {-1, 0};
pair<long, long> RIGHT = {1, 0};


vector<pair<long, long>> directions = {UP, DOWN, LEFT, RIGHT};


pair<long, long> exploreRegion(pair<long, long> position, char regChar){
    long x = position.first;
    long y = position.second;

    if(!isCharAt({x, y}, regChar) || visited[y][x] == true ) return make_pair(0, 0);
    visited[y][x] = true;
    long totalArea = 1;
    long totalCorners = 0;

    //Check if there are corners, for UP, LEFT, RIGHT and DOWN
    if(!isCharAt(position + UP, regChar) && isCharAt(position + LEFT, regChar) && isCharAndUnvisited(position + LEFT + UP , regChar)){
        totalCorners++;
    }
    if(!isCharAt(position + UP , regChar) && isCharAndUnvisited(position + RIGHT, regChar) && isCharAndUnvisited(position + RIGHT + UP , regChar)){
        totalCorners++;
    }
    if(!isCharAt(position + DOWN, regChar) && isCharAt(position + RIGHT, regChar) && isCharAndUnvisited(position + RIGHT + DOWN, regChar)){
        totalCorners++;
    }
    if(!isCharAt(position + DOWN, regChar) && isCharAt(position + LEFT, regChar) && isCharAndUnvisited(position + LEFT + DOWN, regChar)){
        totalCorners++;
    }
    if(!isCharAt(position + LEFT, regChar) && isCharAt(position + UP, regChar) && isCharAndUnvisited(position + UP + LEFT, regChar)){
        totalCorners++;
    }
    if(!isCharAt(position + LEFT, regChar) && isCharAt(position + DOWN, regChar) && isCharAndUnvisited(position + DOWN + LEFT, regChar)){
        totalCorners++;
    }
    if(!isCharAt(position + RIGHT, regChar) && isCharAt(position + DOWN, regChar) && isCharAndUnvisited(position + DOWN + RIGHT, regChar)){
        totalCorners++;
    }
    if(!isCharAt(position + RIGHT, regChar) && isCharAt(position + UP, regChar) && isCharAndUnvisited(position + UP + RIGHT, regChar)){
        totalCorners++;
    }

    //Cases of the edge
    if(!isCharAt(position + LEFT, regChar) && !isCharAt(position + UP, regChar)){
        totalCorners++;
    }
    if(!isCharAt(position + LEFT, regChar) &&!isCharAt(position + DOWN, regChar)){
        totalCorners++;
    }
    if(!isCharAt(position + RIGHT, regChar) &&!isCharAt(position + UP, regChar)){
        totalCorners++;
    }
    if(!isCharAt(position + RIGHT, regChar) &&!isCharAt(position + DOWN, regChar)){
        totalCorners++;
    }


    for(pair<long,long> dir: directions){
        pair<long, long> areaAndCorners = exploreRegion(position + dir, regChar);
        totalArea += areaAndCorners.first;
        totalCorners +=  areaAndCorners.second;
    }
      
    return make_pair(totalArea, totalCorners);


    
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

    long x = 0;
    long y = 0;
    long total = 0;
    while(y < matrix.size()){
        if(visited[y][x] == false){
            pair<long, long> areaPerimeter = exploreRegion({x, y}, matrix[y][x]);
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