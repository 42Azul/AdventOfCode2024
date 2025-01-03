#include <bits/stdc++.h>   
#include <unordered_map>
using namespace std;


struct Trie {
    unordered_map<char, Trie*> children;
    bool isEndOfWord = false;
};



void insert(string toInsert, Trie* child) {
    if(toInsert.size()==0) {
        child->isEndOfWord = true;
        return;
    }
    char c = toInsert[0];
    Trie* actualChild = child->children[c];
    if(!actualChild) {
        actualChild = new Trie();
        child->children[c] = actualChild;
    }
    insert(toInsert.substr(1), actualChild);
} 



long countWays(string &toCheck, Trie* root) {
    int n = toCheck.size();
    vector<long> count(n,0);
    cout << " size is " << n << endl;
    for(int i = 0; i < n; i++) {
        Trie* node = root;
        for(int j = i; j >= 0; j--) {
            char c = toCheck[j];
            node = node->children[c];
            if(!node) break;
            if(node->isEndOfWord){
                if(j>0) count[i]+= count[j-1];
                else count[i]++;
            }
        }
    }



    return count[n-1];
}

int main(){
    string line;
    Trie * root = new Trie();
    getline(cin, line);
    replace(line.begin(), line.end(),',', ' ');
    istringstream iss(line);
    while(iss >> line){
        //Reverse string and insert into trie
        reverse(line.begin(), line.end());
        insert(line, root);
    }

    getline(cin, line);

    long total = 0;
    while(getline(cin, line)){
        long totalForThisLine = countWays(line, root);
        cout << totalForThisLine << " for line " << line << endl;
        total += totalForThisLine;
    }
    cout << total << endl;

}