#include<bits/stdc++.h>
using namespace std;



long calculateSequenceSum(long izq, long increase){
    long sequenceSum = ((increase)*(2*izq+increase-1)) /2;
    return sequenceSum;
}


int main(){
    string input;
    cin >> input;
    string untouchedInput = input;
    long indIz = 0;
    long indReal = 0;
    long indDer = input.size()%2==0 ? input.size() - 2 : input.size() - 1;
    long checkSum = 0;
    long newSum = 0;
    while(indIz < input.size()){
        if(input[indIz] == '0'){
            indReal += (untouchedInput[indIz] - '0');
        } 
        else {
            newSum = calculateSequenceSum(indReal, input[indIz]-'0')*((indIz)/2);
            checkSum += newSum;
            indReal += input[indIz] - '0';
        }
        indIz ++;
        if(indIz < indDer){
            long amountOfZeros = input[indIz] - '0';
            long i = 0;
            long indRealTemp = indReal;
            long indDerTemp = indDer;
            while(i < amountOfZeros && indIz < indDerTemp){
                long amountOfLastChar = input[indDerTemp] - '0';
                if(amountOfLastChar > 0 && amountOfLastChar <= (amountOfZeros - i)){
                        newSum = calculateSequenceSum(indRealTemp, amountOfLastChar)*((indDerTemp)/2);
                        checkSum += newSum;
                        indRealTemp += amountOfLastChar;
                        input[indDerTemp] -= amountOfLastChar;
                        i+= amountOfLastChar;
                } else {
                    indDerTemp-=2;
                }

            }
            indReal += amountOfZeros;
        }
        indIz ++;

    }
    cout << checkSum << endl;



}