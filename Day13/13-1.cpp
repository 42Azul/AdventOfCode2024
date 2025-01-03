#include <bits/stdc++.h>
using namespace std;


namespace std{


std::pair<long,long> operator+(const std::pair<long,long> & l,const std::pair<long,long> & r) {   
    return {l.first+r.first,l.second+r.second};                                    
}    
}


pair<long, long> getButtonIncrement(string buttonLine){
    long x, y;
    istringstream is(buttonLine);
    is.ignore(12);
    is >> x;
    is.ignore(4);
    is >> y;
    return {x, y};
}

pair<long, long> getPrizePosition(string positionLine){
    long x, y;
    istringstream is(positionLine);
    is.ignore(9);
    is >> x;
    is.ignore(4);
    is >> y;
    return {x, y};
}


int main(){
    long total = 0;
    string lineA, lineB, linePos;
    while(getline(cin, lineA)){
        getline(cin, lineB);
        getline(cin, linePos);
        pair<long, long> incrementA = getButtonIncrement(lineA);
        pair<long, long> incrementB = getButtonIncrement(lineB);
        pair<long, long> prizePosition = getPrizePosition(linePos);

        cout << "BUTTON INCREMENTS AND PRIZE POSITION: " << incrementA.first << " " << incrementA.second << " " << prizePosition.first << " " << prizePosition.second << endl;


        long a  = incrementA.first;
        long b = incrementB.first;
        long c = incrementA.second;
        long d = incrementB.second;
        long e = prizePosition.first;
        long f = prizePosition.second;
        
        long denominator = (a*d - b*c);
        long mWithoutDenominator = d*e - b*f;
        long nWithoutDenominator = a*f - c*e;

        if(denominator!=0 && mWithoutDenominator % denominator == 0 && nWithoutDenominator % denominator == 0){
            long m = mWithoutDenominator / denominator;
            long n = nWithoutDenominator / denominator;
            total += 3*m + n;
            cout << "For the prize position " << prizePosition.first << " and " << prizePosition.second << " the required m and n are "<< m << " and " << n << endl;
        }
        else{
            cout << "No solution found for the prize position " << prizePosition.first << " and " << prizePosition.second << endl;
        }
        cout << total << endl;
        cin.ignore();

    }
}