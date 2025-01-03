#include <bits/stdc++.h>
using namespace std;


int NUM_OF_CHARS = 'z'- 'a' + 1;


int fromString(string str){
    char firstChar = str[0];
    return (firstChar - 'a')*(NUM_OF_CHARS) + str[1] - 'a';
}

string toString(int charValue){
    char firstChar = 'a' + charValue/NUM_OF_CHARS;
    char secondChar = 'a' + charValue % NUM_OF_CHARS;
    return {firstChar, secondChar};
}

vector<vector<bool>> connectedGraph(NUM_OF_CHARS*NUM_OF_CHARS, vector<bool>(NUM_OF_CHARS*NUM_OF_CHARS, false));

int numOfFirst = fromString("ta");
int numOfLast = fromString("tz");

bool isInRangeOfT(int value){
    return value >= numOfFirst && value <= numOfLast;
}


int main(){
    char a, b;
    string first, second;

    while(getline(cin, first, '-') && getline(cin, second)){
        int firstValue = fromString(first);
        int secondValue = fromString(second);
        connectedGraph[firstValue][secondValue] = true;
        connectedGraph[secondValue][firstValue] = true;
    }

    int currentChecked = numOfFirst;
    long total = 0;

    while(currentChecked <= numOfLast){
        vector<int> neighbors;
        for(int i = 0; i < NUM_OF_CHARS*NUM_OF_CHARS; i++){
            if(connectedGraph[currentChecked][i]){
                neighbors.push_back(i);
            }

        }

        for(int i = 0; i < neighbors.size(); i++){
            int neighborFirst = neighbors[i];
            bool isPrevAndT = neighborFirst < currentChecked && isInRangeOfT(neighborFirst);
            for(int j = i+1; j < neighbors.size(); j++){
                int neighborSecond = neighbors[j];
                bool isNextAndT = neighborSecond < currentChecked && isInRangeOfT(neighborSecond);
                if(((!isPrevAndT && !isNextAndT) && connectedGraph[neighborFirst][neighborSecond])){
                    cout << " " << toString(neighborFirst) << " " << toString(neighborSecond) << " " <<toString(currentChecked) << endl;
                    total++;
                }
        
            }
        }


        currentChecked++;
    }
    cout << total << endl;

}


