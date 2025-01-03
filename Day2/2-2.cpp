#include <bits/stdc++.h>
using namespace std;


bool isValid(vector<int> values, int skip){
    if (values.size() <=1) return true;

    int valuePrev, diff, sign;
    sign = 0;
    bool isValid = true;
    int startIndex = 0 + (skip == 0);
    valuePrev = values[startIndex];
    for(int i = startIndex + 1; i < values.size(); i++){
        if (i == skip) continue;
        diff = valuePrev - values[i];
        sign = sign!=0 ? sign: (diff>0) - (diff<0);
        if(abs(diff) > 3 || diff * sign <= 0){
            return false;
        }
        valuePrev = values[i];
    }
    return true;
}

int main(){

    string line;
    int count = 0;
    int value1;
    while(getline(cin, line)){
        istringstream iss(line);
        vector<int> values;
        while(iss >> value1){
            values.push_back(value1);
        }
        for(int skip = 0; skip < values.size(); skip++){
            if(isValid(values, skip)){
                count++;
                break;
            }
        }
        
    }

    cout << count << endl;
}