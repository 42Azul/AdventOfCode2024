#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

namespace std{

    ii operator+(const ii& a, const ii& b){
        return {a.first + b.first, a.second + b.second};
    }
}


vector<vector<char>> matrix;


vector<ii> validDirections = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<ii> cheatingDirections = {{2, 0}, {1,1}, {1,-1}, {-2, 0}, {-1, 1}, {-1, -1}, {0,-2}, {0, 2}};



bool isEmpty(ii position){
    int x = position.first;
    int y = position.second;
    return x >= 0 && y >= 0 && x < matrix[0].size() && y < matrix.size() && matrix[y][x] != '#';
}

int main(){
    string line;
    char cell;
    ii startingPos;
    ii endingPos;
    while(getline(cin, line)){
        istringstream iss(line);
        vector<char> row;
        while(iss >> cell){
            if(cell == 'S'){
                startingPos = {row.size(), matrix.size()};
            }
            else if(cell == 'E'){
                endingPos = {row.size(), matrix.size()};
            }
            row.push_back(cell);
        }
        matrix.push_back(row);
    }



    //First we use BFS to find minimum distance and we make it from the ENDING
    vector<ii> seen;
    queue<ii> q;
    q.push(endingPos);
    seen.push_back(endingPos);
    vector<vector<int>> distances(matrix.size(), vector<int>(matrix[0].size(), INT_MAX));
    distances[endingPos.second][endingPos.first] = 0;
    while(!q.empty()){
        ii current = q.front();
        q.pop();
        for(ii direction : validDirections){
            ii next = current + direction;
            if(isEmpty(next) && distances[current.second][current.first] + 1 < distances[next.second][next.first]){
                distances[next.second][next.first] = distances[current.second][current.first] + 1;
                q.push(next);
                seen.push_back(next);
            }
        }
    }

    int legalDistance = distances[startingPos.second][startingPos.first];
    cout << legalDistance << endl;


    //Now we use BFS from the starting point but we also allow the cheating directions but we do not clear the distances
    q.push(startingPos);
    seen.clear();
    seen.push_back(startingPos);
    vector<vector<int>> distancesFromStartingPos(matrix.size(), vector<int>(matrix[0].size(), INT_MAX));
    distancesFromStartingPos[startingPos.second][startingPos.first] = 0;
    while(!q.empty()){
        ii current = q.front();
        q.pop();
        for(ii direction : validDirections){
            ii next = current + direction;
            if(isEmpty(next) && distancesFromStartingPos[current.second][current.first] + 1 < distancesFromStartingPos[next.second][next.first]){
                distancesFromStartingPos[next.second][next.first] = distancesFromStartingPos[current.second][current.first] + 1;
                q.push(next);
                seen.push_back(next);
            }
        }
    }

    //Now we have best distance from one and other side
    //We will go through each element of the grid and try to check if the difference between it and the other side
    //using the cheating directions is better than the original legal distance


    long total = 0;

    for(int y = 0; y < distancesFromStartingPos.size(); y++){
            for(int x = 0; x < distancesFromStartingPos[0].size(); x++){
                if(matrix[y][x]!= '#'){
                    for(ii direction : cheatingDirections){
                        ii next = {x + direction.first, y + direction.second};
                        if(isEmpty(next)){
                            int newCheatingDistance = 2 + distancesFromStartingPos[y][x] + distances[next.second][next.first];
                            if(newCheatingDistance + 100 <= legalDistance){
                                cout << "Found better path with " << next.first << " and " << next.second << " and new Distance " << newCheatingDistance << endl;
                                total++;
                            }
                    }
                }
            }
        }
    }
    cout << total << endl;
    

    return 0;
}