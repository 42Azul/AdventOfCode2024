#include<bits/stdc++.h>
using namespace std;



long calculateSequenceSum(long izq, long increase){
    long sequenceSum = ((increase)*(2*izq+increase-1)) /2;
    cout << sequenceSum << endl;
    return sequenceSum;


}


int main(){
    string input;
    cin >> input;
    long indIz = 0;
    long indReal = 0;
    long indDer = input.size()%2==0 ? input.size() - 2 : input.size() - 1;
    long checkSum = 0;
    while(indIz <= indDer){
        long newSum = calculateSequenceSum(indReal, input[indIz]-'0')*((indIz)/2);
        checkSum += newSum;
        indReal += input[indIz] - '0';
        indIz ++;
        if(indIz < indDer){
            long amountOfZeros = input[indIz] - '0';
            long i = 0;
            while(i < amountOfZeros && indIz < indDer){
                if(input[indDer] == '0'){
                    indDer-=2;
                }
                else{
                    long amountOfLastChar = min(long(input[indDer] - '0'), amountOfZeros-i);
                    newSum = calculateSequenceSum(indReal, amountOfLastChar)*((indDer)/2);

                    checkSum += newSum;
                    indReal += amountOfLastChar;
                    input[indDer] -= amountOfLastChar;
                    i+= amountOfLastChar;
                }

            }
        }
        indIz ++;

    }
    cout << checkSum << endl;



}