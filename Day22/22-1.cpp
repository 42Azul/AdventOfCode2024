#include <bits/stdc++.h>
using namespace std;




long long calculateNewSecretNumber(long long secretNumber){
    secretNumber = ((secretNumber << 6) ^ secretNumber) % (1 << 24);
    secretNumber = ((secretNumber >> 5) ^ secretNumber) % (1 << 24);
    secretNumber = ((secretNumber << 11) ^ secretNumber) % (1 << 24);
    return secretNumber;
}



int main(){
    long long input;
    long long total = 0;
    while(cin >> input){
        for(int i = 0; i < 2000 ; i++){
            input = calculateNewSecretNumber(input);
        }
        cout << input << endl;
        total += input;

    }
    cout << total << endl;

}