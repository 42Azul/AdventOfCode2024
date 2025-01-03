#include <bits/stdc++.h>
using namespace std;


int MAX_HEIGHT =5;
int MAX_WIDTH =5;


vector<vector<int>> keys;

vector<vector<int>> locks;




bool areFitting(vector<int>& key, vector<int>& lock){
    for(int i = 0; i< key.size(); i++){
        if(key[i] + lock[i] > MAX_HEIGHT) return false;
    }
    return true;
}



int main(){
    string toCheckLine;
    while(getline(cin, toCheckLine)){
        vector<int> row(MAX_WIDTH, 0);
        for(int i = 0; i < MAX_HEIGHT; i++){
            string line;
            getline(cin, line);
            for(int j = 0; j < MAX_WIDTH; j++){
                if(line[j] == '#') row[j]++;
            }
        }
        if(toCheckLine[0] == '#'){
            keys.push_back(row);
        } else{
            locks.push_back(row);
        }
        //We skip the empty useless line and the empty line
        getline(cin, toCheckLine);
        getline(cin, toCheckLine);
    }


    for(int i = 0; i < keys.size(); i++){
        for(int j = 0; j < MAX_WIDTH; j++){
            cout << keys[i][j];
        } 
        cout << endl;
    }


    long total = 0;
    for(int i = 0; i < keys.size(); i++){
        for(int j = 0; j < locks.size(); j++){
            if(areFitting(keys[i], locks[j])){
                cout << " Are fitting: " << i <<  " " << j <<endl;
                total++;
            }
        }
    }
    cout << total << endl;

    return 0;




}
