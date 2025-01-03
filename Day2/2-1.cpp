#include <bits/stdc++.h>
using namespace std;

int main(){

    string line;
    int count = 0;
    bool isValid = true;
    int value1, value2, diff, sign;
    while(getline(cin, line)){
        istringstream iss(line);
        isValid = true;
        iss >> value1;
        sign = 0;
        while(isValid && (iss >> value2)){
            diff = value1 - value2;
            sign = sign!=0 ? sign: (diff>0) - (diff<0);
            if(abs(diff) > 3 || diff * sign <= 0){
                isValid = false;
            }
            value1 = value2;
        }
        count += isValid;
        if(!isValid){
            cout << line << endl;
        }

    }

    cout << count << endl;
}