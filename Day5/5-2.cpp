#include<bits/stdc++.h>
using namespace std;



bool tryToFixRule(vector<int> &elements, pair<int, int> rule) {
    int secondFound = -1;
    for(int i = 0; i < elements.size(); i++) {
        if(elements[i] == rule.first && secondFound!=-1) {
            elements.erase(elements.begin() + i);
            elements.insert(elements.begin() + secondFound, rule.first);
            return true;
        }
        if(elements[i] == rule.first) {
            return false;
        }
        if(elements[i] == rule.second) {
            secondFound = i;
        }
    }
    return false;
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
        bool wasWrongPage = false;
        for(auto rule : rules){
            if(tryToFixRule(currentPages, rule)){
                wasWrongPage = true;
            }
        }
        if(wasWrongPage){
            cout << "LINE WRONG: " << line << endl;
            for (int page : currentPages){
                cout << page << " ";
            }
            cout << endl;
            sum += currentPages[currentPages.size()/2];
        }
    }

    cout << sum << endl;

    return 0;

}