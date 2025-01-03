#include <bits/stdc++.h>
using namespace std;

int main() {

   char readValue;
   long sum = 0;
   
   string toCheck = "mul(";
   string strEnable = "do()";
   string strDisable = "don't()";
   bool enabled = true;
   int pos = 0;
   int posEnable = 0;
   int posDisable = 0;

   int firstDigit, secondDigit = 0;
   while(cin >> readValue) {

    if(readValue == strEnable[posEnable]) {
        posEnable++;
        if(posEnable == strEnable.size()){
            enabled = true;
            posEnable = 0;
        }
    } else{
        posEnable = (readValue == strEnable[0]);
    }
    if (posDisable < strDisable.size() && readValue == strDisable[posDisable]) {
        posDisable++;
        if(posDisable == strDisable.size()){
            enabled = false;
            posDisable = 0;
        }
    } else {
        posDisable = (readValue == strDisable[0]);
    }

    if(enabled){
        // Checks for the presence fo the 'mul(' only if enabled
        if(pos < toCheck.size() && readValue == toCheck[pos]) {
            pos++;
        }
        else if (pos == toCheck.size() && isdigit(readValue)) {
            firstDigit = readValue - '0';
            pos++;
        }
        else if (pos == toCheck.size() + 1 && isdigit(readValue)) {
            firstDigit = firstDigit * 10 + (readValue - '0');
        } else if (pos == toCheck.size() + 1 && readValue == ',') {
            pos++;
        } else if (pos == toCheck.size() + 2 && isdigit(readValue)) {
            secondDigit = readValue - '0';
            pos++;
        } else if (pos == toCheck.size() + 3 && isdigit(readValue)) {
            secondDigit = secondDigit * 10 + (readValue - '0');
        } else if (pos == toCheck.size() + 3 && readValue == ')') {
            cout << "mul(" << firstDigit << "," << secondDigit << ") = " << firstDigit * secondDigit << endl;
            sum += firstDigit * secondDigit;

            firstDigit = 0;
            secondDigit = 0;
            pos = 0;
        } else if(readValue == toCheck[0]){
            pos = 1;
            firstDigit = 0;
            secondDigit = 0;
        } else {
            pos = 0;
            firstDigit = 0;
            secondDigit = 0;
        }
    }


   }

   cout << sum << endl;

   return 0;


}