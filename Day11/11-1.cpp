#include <bits/stdc++.h>
using namespace std;



long getDigits(long n){
    long count = 0;
    while(n > 0){
        n = n / 10;
        count++;
    }
    return count;
}


long int10Pow(long exponent){
    if(exponent == 0) return 1;
    else if (exponent%2!=0) return 10*int10Pow(exponent - 1);
    else{
        long halfExponent = int10Pow(exponent/2);
        return halfExponent*halfExponent;
    }
}





pair<long, long> getSplit(long n, long digits){
    long powerOf10 = int10Pow(digits/2);
    long firstPart = n / powerOf10;
    long secondPart = n % powerOf10;
    return make_pair(firstPart, secondPart);
}




void iterateStones(list<long> &numbers){
    list<long>::iterator it = numbers.begin();
    while(it!=numbers.end()){
        if(*it == 0) *it = 1;
        else{
            long digits = getDigits(*it);
            if(digits %2 == 0){
                pair<long, long> split = getSplit(*it, digits);
                numbers.insert(it, split.first);
                *it = split.second;
            }
            else{
                *it *=2024;
            }
        }
        it++;
    }
}



int main(){
    list<long> numbers;
    long number;
    while(cin>>number) numbers.push_back(number);

    for(int i= 0; i< 39; i++){  
        iterateStones(numbers);
    }
    cout << numbers.size() << endl;     
}