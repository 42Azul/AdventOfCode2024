#include <bits/stdc++.h>
#include <map>
using namespace std;

namespace std{
    pair<int, int> operator-(const pair<int, int>& a, const pair<int, int>& b){
        return {a.first - b.first, a.second - b.second};
    }
}


typedef pair<int, int> ii;


struct State{
    char origin;
    char destiny;
    int depth;
};

auto comp = [](const State& state1, const State& state2){
    if(state1.origin < state2.origin) return true;
    if(state1.origin == state2.origin && state1.destiny < state2.destiny) return true;
    if(state1.origin == state2.origin && state1.destiny == state2.destiny && state1.depth < state2.depth) return true;
    return false;
};

map<State, long long, decltype(comp)> stateMap(comp);

unordered_map<char, ii> keypadMap;
unordered_map<char, ii> robotKeypadMap;


string getStringByPosition(ii position){
    if(position.first > 0) return string(position.first, '>');
    if(position.first < 0) return string(-position.first, '<');
    if(position.second > 0) return string(position.second, 'v');
    if(position.second < 0) return string(-position.second, '^');
    return "";
}


long long getCost(string expectedString, unordered_map<char, ii>& positionMap, int depth);


long long getCostBetweenPosition(State status, unordered_map<char, ii>& positionMap, int depth){
    if(depth == 0)return 1;
    auto it = stateMap.find(status);
    if (it == stateMap.end()) {
        ii origPos = positionMap[status.origin];
        ii destinyPos = positionMap[status.destiny];
        ii newDir = destinyPos - origPos;
        ii badPosition = positionMap['*'];
        auto isBadPosition = [&] (ii position){return position == badPosition;};
        long long expectedCost = 999999999999999999;
        if(!isBadPosition({origPos.first, destinyPos.second})){
            string movement = getStringByPosition({0, newDir.second});
            movement.append(getStringByPosition({newDir.first, 0}));
            movement.push_back('A');
            expectedCost = getCost(movement, robotKeypadMap, depth -1);
        }
        if(!isBadPosition({destinyPos.first, origPos.second})){
            string movement = getStringByPosition({newDir.first, 0});
            movement.append(getStringByPosition({0, newDir.second}));
            movement.push_back('A');
            expectedCost = min(expectedCost, getCost(movement, robotKeypadMap, depth -1));
        }
        stateMap[status] = expectedCost;
        return expectedCost;
    }
    else {
        return it->second;
    }
}




long long getCost(string expectedString, unordered_map<char, ii>& positionMap, int depth){
    long long total = 0;
    char currentCharacter = 'A';
    for(char character : expectedString){
        State currentState = {currentCharacter, character, depth};
        total += getCostBetweenPosition(currentState, positionMap, depth);
        currentCharacter = character;
    }
    return total;

}


int main(){

    string keypad = "789456123*0A";
    string robotKeypad = "*^A<v>";



    //First we populate the keypad
    for(int i = 0; i< 4;i++){
        for(int j = 0; j< 3; j++){
                keypadMap[keypad[i*3+j]] = {j, i};
            }
        }

    //Then we populate the robot keypad
    for(int i = 0; i< 2; i++){
        for(int j = 0; j<3 ; j++){
            robotKeypadMap[robotKeypad[i*3+j]] = {j, i};
        }
    }


    string line;
    long long total = 0;
    while(getline(cin, line)){
        long long numberOfMovements = getCost(line, keypadMap, 26);
        line.pop_back(); //Remove the A in the end of the line
        cout << "Number of moves: " << numberOfMovements << endl;
        long long newValue = stoi(line) * numberOfMovements;
        total+=newValue;
    }

    cout << total <<endl;
    return 0;


}


