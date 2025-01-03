#include <bits/stdc++.h>   
#include <unordered_set>
using namespace std;


unordered_set<string> prefixes;



bool canBeMade(string word){
    if(prefixes.contains(word)) return true;
    if(word.size() <=1 ) return false;
    for(int i = 0; i < word.size(); i++){
        string prefix = word.substr(0, i+1);
        string suffix = word.substr(i+ 1, word.size());
        cout << prefix << " " << suffix << endl;
        if(prefixes.contains(prefix) && canBeMade(suffix)){
            prefixes.insert(word);
            return true;
        }
    }
    return false;


}

int main(){
    string line;
    getline(cin, line);
    replace(line.begin(), line.end(),',', ' ');
    istringstream iss(line);
    while(iss >> line){
        prefixes.insert(line);
        cout << line << " inserted" << endl;
    }

    getline(cin, line);


    cout << line;
    long total = 0;
    while(getline(cin, line)){
        if(canBeMade(line)){
            cout << "YES" << endl;
            total++;
        } else {
            cout << "NO" << endl;
        }

    }
    cout << total << endl;








}