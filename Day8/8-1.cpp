#include <bits/stdc++.h>
using namespace std;



int MAX_X = 50;
int MAX_Y = 50;

void processNodes(set<pair<int, int>> &antinodes, set<pair<int, int>> &existingCharacters, int x, int y){

    for(pair<int, int> existingCharacter : existingCharacters){
        pair<int, int> diff = make_pair(x - existingCharacter.first, y - existingCharacter.second);

        pair<int, int> newAntinodeUp = make_pair(existingCharacter.first - diff.first, existingCharacter.second - diff.second);
        pair<int, int> newAntinodeDown = make_pair(x + diff.first,y + diff.second);
        if(newAntinodeUp.first >= 0 && newAntinodeUp.first < MAX_X && newAntinodeUp.second >= 0 && newAntinodeUp.second < MAX_Y){
            antinodes.insert(newAntinodeUp);
        }
        if(newAntinodeDown.first >= 0 && newAntinodeDown.first < MAX_X && newAntinodeDown.second >= 0 && newAntinodeDown.second < MAX_Y){
            antinodes.insert(newAntinodeDown);
        }
    }
}


int main(){
    string line;
    set<pair<int, int> > antinodes;
    map<char, set<pair<int, int> > > mapCharacters;
    int x = 0;
    int y = 0;
    while(getline(cin, line)){
        char ch;
        istringstream iss(line);
        x = 0;
        while(iss >> ch){
            if(ch != '.'){
                cout << "Processing character " << ch << " in (" << x << "," << y << ")" << endl;
                processNodes(antinodes, mapCharacters[ch], x, y);
                mapCharacters[ch].insert(make_pair(x, y));
            }
        
            x++;
        }
        y++;
        
    }
    cout << antinodes.size() << endl;
}