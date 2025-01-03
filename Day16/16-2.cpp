#include<bits/stdc++.h>
#include<queue>
using namespace std;

struct state {
    pair<long, long> position;
    char direction;
};

namespace std{
    std::pair<long,long> operator+(const std::pair<long,long> & l,const std::pair<long,long> & r) {   
        return {l.first+r.first,l.second+r.second};                                    
    }    

    std::pair<long,long> operator-(const std::pair<long,long> & l,const std::pair<long,long> & r){
        return {l.first-r.first, l.second-r.second};
    }
}



int compare(pair<long, state> & l, pair<long, state> & r) {
    return l.first > r.first;
}

vector<vector<char>> world;


map<char, pair<long,long> > directions = {{'>',{1,0}}, { '<', {-1, 0}}, { '^', {0,-1}}, {'v', {0,1}}};



vector<vector<map<char, long>>> minDistances;
vector<vector<map<char, long>>> seen;


long getDistance(state const & state) {
    long x = state.position.first;
    long y = state.position.second;
    return minDistances[y][x][state.direction];
}

void setDistance(state const & state, long distance) {
    long x = state.position.first;
    long y = state.position.second;
    minDistances[y][x][state.direction] = distance;
}


bool isSeen(state const & currState) {
    long x = currState.position.first;
    long y = currState.position.second;
    return seen[y][x][currState.direction];
}

void setSeen(state const & currState){
    long x = currState.position.first;
    long y = currState.position.second;
    seen[y][x][currState.direction] = true;
}




char charAt(pair<long, long> position) {

    return world[position.second][position.first];

}



bool areOppositeDirections(char direction1, char direction2) {
    return (direction1 == 'v' && direction2 == '^') || (direction1 == '^' && direction2 == 'v') || (direction1 == '<' && direction2 == '>') || (direction1 == '>' && direction2 == '<');
}

vector<pair<long, state>> getNeighborsWithCosts(state const & currState){
    vector<pair<long, state>> neighbors;
    for(auto direction: directions){
        if(areOppositeDirections(currState.direction, direction.first)) continue; // Skip if moving in opposite directions
        pair<long, long> newPosition = currState.position + direction.second;
        if(charAt(newPosition) != '#'){
            neighbors.push_back({1 + 1000*(direction.first!=currState.direction), {newPosition, direction.first}});
        }

    }
 
 
    return neighbors;
}



///// FOR 16-2 

auto comparePairs = [](pair<long, long> a, pair<long, long> b){return a.first < b.first || (a.first == b.first && a.second < b.second);};

set<pair<long,long>, decltype(comparePairs)> seenPairs(comparePairs);


vector<pair<long, state>> getNeighborsWithCostsBacktrack(state const & currState){
    vector<pair<long, state>> neighbors;
    for(auto direction: directions){
        if(areOppositeDirections(currState.direction, direction.first)) continue; // Skip if moving in opposite directions
        pair<long, long> newPosition = currState.position - direction.second;
        if(charAt(newPosition) != '#'){
            for(auto directionExtra : directions){
                if(areOppositeDirections(directionExtra.first, currState.direction)) continue; // Skip if moving in opposite directions
                neighbors.push_back({1 + 1000*(directionExtra.first!=currState.direction), {newPosition, directionExtra.first}});
                cout << "Neighbor " << newPosition.first << " " << newPosition.second <<  " with direction " << directionExtra.first << endl;
            }
        }
    }
 
 
    return neighbors;
}

void getOriginTrace(state const & currState){
    long distance = getDistance(currState);
    if(distance == 0) return;
    setDistance(currState, 0);
    for(auto neighbor: getNeighborsWithCostsBacktrack(currState)){
        long neighborDistance = getDistance(neighbor.second);
        cout << "The current distance is: " << distance << " of " << currState.position.first << " " << currState.position.second << endl;
        cout << "The neighbor distance is: " << neighborDistance << " of " << neighbor.second.position.first << " " << neighbor.second.position.second << endl;
        if(distance - neighbor.first == neighborDistance){
            cout << "This entered, because equals  with direction " << neighbor.second.direction << endl;
            seenPairs.insert(neighbor.second.position);
            getOriginTrace(neighbor.second);
        }
    }

}



int main(){
    string line;
    state startingState;
    pair<long,long> endingPosition;
    while(getline(cin, line)){
        vector<char> row;
        vector<map<char, long>> rowDistances;
        vector<map<char, long>> rowSeen;
        istringstream is(line);
        char c;
        while(is >> c){
            if(c == 'S'){
                startingState.position = {row.size(), world.size()};
                startingState.direction = '>';
                c = '.';
            } 
            else if(c == 'E'){
                endingPosition = {row.size(), world.size()};
                c = '.';
            }
            row.push_back(c);
            rowDistances.push_back(map<char, long>());
            rowSeen.push_back(map<char, long>());
            
        }
        world.push_back(row);
        minDistances.push_back(rowDistances);
        seen.push_back(rowSeen);
    }

    //Make lambda for the min heap priority queue of long, state, where long is the minimum distance

    priority_queue<pair<long, state>, vector<pair<long, state>>, decltype(&compare)> minHeap(&compare);

    minHeap.push({0, startingState});
    while(!minHeap.empty()){
        pair<long, state> current = minHeap.top();
        minHeap.pop();
        setSeen(current.second);
        vector<pair<long, state>> currentNeighbors = getNeighborsWithCosts(current.second);
        for(pair<long, state> neighbor : currentNeighbors){
            if(!isSeen(neighbor.second)){
                long neighborDistance = getDistance(neighbor.second);
                long currentDistance = current.first;
                if(neighborDistance == 0 || neighborDistance > currentDistance + neighbor.first){
                    setDistance(neighbor.second, currentDistance + neighbor.first);
                    minHeap.push({currentDistance + neighbor.first, neighbor.second});
                }

            }
        }

    }

    long endDistance = 999999999999999999;
    state endState = {endingPosition, 'E'};
    for(auto direction: directions){
        endState.direction = direction.first;
        long potentialDirectionDistance = getDistance(endState);
        if(potentialDirectionDistance !=0){
            endDistance = min(endDistance, potentialDirectionDistance);
        }
    }

    cout << "Shortest distance to the exit: " << endDistance << endl;


    long viewedPositions = 0;
    for(auto direction: directions){
        endState.direction = direction.first;
        long potentialDirectionDistance = getDistance(endState);
        if(potentialDirectionDistance == endDistance){
            getOriginTrace(endState);
        }
    }



    for(auto seenPair: seenPairs){
        cout << seenPair.first << " " << seenPair.second << endl;

    }

    cout << "Total number of unique paths: " << 1 + seenPairs.size() << endl;


    return 0;



}










