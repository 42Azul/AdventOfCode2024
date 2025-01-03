#include <bits/stdc++.h>
using namespace std;



bool isTestResult(vector<int> &numbers, long pos, long acc, long result){
    if (acc == result && pos == numbers.size()) return true;
    
    if(acc > result || pos >= numbers.size()) return false;
    
    return (isTestResult(numbers, pos+1, acc + numbers[pos], result) || isTestResult(numbers, pos+1, acc*numbers[pos], result));
}



int main(){

    string line;
    long sum = 0;
    while(getline(cin, line)){
        istringstream iss(line);
        long result, number;
        iss >> result;
        iss.ignore();
        vector<int> numbers;
        while(iss >> number){
            numbers.push_back(number);
        }
        if(numbers.size() < 2 ) cout << " " << numbers.size() << " " << result << endl;
        if(isTestResult(numbers, 1, numbers[0], result)){
            sum += result;
        }
        
    }
    cout << sum << endl;
}