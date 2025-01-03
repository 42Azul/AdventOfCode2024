#include<bits/stdc++.h>
using namespace std;



bool ruleIsValid(vector<int> elements, pair<int, int> rule) {
    bool secondFound = false;
    for(int i = 0; i < elements.size(); i++) {
        if(elements[i] == rule.first && secondFound) {
            return false;
        }
        if(elements[i] == rule.first) {
            return true;
        }
        if(elements[i] == rule.second) {
            secondFound = true;
        }
    }
    return true;


}



int main() {

    string line;
    set<pair<int, int>> rules;
    while(getline(cin, line) && line.length() > 0) {
        istringstream iss(line);
        int prePrint, postPrint;
        iss >> prePrint;
        iss.ignore();
        iss >> postPrint;
        rules.insert({prePrint, postPrint});
    }


    long long sum = 0;
    while(getline(cin, line)){
        vector<int> currentPages;
        istringstream iss(line + ',');
        int bookPage;
        bool isValidLine = true;
        while(iss >> bookPage){
            iss.ignore();
            currentPages.push_back(bookPage);
        }
        if( all_of(rules.begin(), rules.end(), [currentPages](pair<int, int> rule){return ruleIsValid(currentPages, rule);})){
            cout << "YES  for the line: " << line << endl;
            sum += currentPages[currentPages.size()/2];
        }
    }

    cout << sum << endl;

    return 0;

}