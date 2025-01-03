#include <bits/stdc++.h>
using namespace std;

namespace std{
    pair<int, int> operator-(const pair<int, int>& a, const pair<int, int>& b){
        return {a.first - b.first, a.second - b.second};
    }
}


typedef pair<int, int> ii;



vector<char> directions = {'>', 'v', '^', '<'};






//Method to retrieve all the movements of a robot
string getRobotMovements(string expectedString, unordered_map<char, ii> positionMap){
    string movement = "";
    ii newPos = positionMap['A'];
    ii badPosition = positionMap['*'];
    auto isBadPosition = [&] (ii position){return position == badPosition;};
    for(char key : expectedString){
            ii newDir = positionMap[key]- newPos;
            while(newDir.first != 0 || newDir.second != 0){
                if( newDir.first < 0 && !isBadPosition({positionMap[key].first, newPos.second})){
                    movement.append(abs(newDir.first), '<');
                    newDir.first = 0;
                    newPos.first = positionMap[key].first;
                }
                if(newDir.second > 0 && !isBadPosition({newPos.first, positionMap[key].second})){
                    movement.append(newDir.second, 'v');
                    newDir.second = 0;
                    newPos.second = positionMap[key].second;
                }
                if(newDir.first > 0 && !isBadPosition({positionMap[key].first, newPos.second})){
                    movement.append(newDir.first, '>');
                    newDir.first = 0;
                    newPos.first = positionMap[key].first;
                }
                if(newDir.second < 0 && !isBadPosition({newPos.first, positionMap[key].second})){
                    movement.append(abs(newDir.second), '^');
                    newDir.second = 0;
                    newPos.second = positionMap[key].second;
                }
            }
            newPos = positionMap[key];
            movement.push_back('A');
    }
    return movement;
}


int main(){

    unordered_map<char, ii> keypadMap;
    unordered_map<char, ii> robotKeypadMap;

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
    string keypadMovements;
    long total = 0;
    while(getline(cin, line)){
        keypadMovements = getRobotMovements(line, keypadMap);
        keypadMovements = getRobotMovements(keypadMovements, robotKeypadMap);
        keypadMovements = getRobotMovements(keypadMovements, robotKeypadMap);
        cout << keypadMovements << endl;
        cout << keypadMovements.size() << endl;
        line.pop_back(); //Remove the A in the end of the line
        long newValue = stoi(line) * keypadMovements.size();
        cout <<newValue<<endl;
        total+=newValue;
    }

    cout << total <<endl;
    return 0;


}


