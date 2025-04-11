#include <bits/stdc++.h>
using namespace std;



unsigned long long int A = 0;
unsigned long long int B = 0;
unsigned long long int C = 0;

vector<unsigned long long int> code;




int main(){
    code = {2,4,1,3,7,5,1,5,0,3,4,2,5,5,3,0};

    //As the element A is checked against modulo 8, we can do iterative process
    //on the last 3 bits and build the result 8 bits per 8 bits.
    vector<unsigned long long int> increments_first = {1};

    bool isEqual = false;
    unsigned long long int Abase, AbasePrev;

    for(long long unsigned int digit = 1; digit <= code.size() && isEqual==false; digit++){
        cout << "Starting with digit " << digit << endl;
        vector<unsigned long long int> increments_next;
        unsigned long long int i = 0;
        Abase = 0;
        AbasePrev = Abase;

        unsigned long long int maxValue = 1 << (10 + digit*3);
        while(isEqual == false && Abase < maxValue){
            Abase += increments_first[i];
            i = (i+1)%increments_first.size();
            A = Abase;
            B = 0;
            C = 0;
            //cout << "Initial values for register A is " << A << endl;
            isEqual = A > 0;
            long j = 0;
            while(isEqual && j < code.size() && A > 0){
                B = (A%8)^3;
                C = A >> B;
                B = B ^ 5 ^ C;
                A = A >> 3;
                isEqual = (code[j] == (B % 8));
                if(isEqual && j == digit) {
                    increments_next.push_back(Abase - AbasePrev);
                    AbasePrev = Abase;
                }
                j++;
            }
            isEqual = isEqual && A == 0 && (j == code.size());
        }
        increments_next.push_back(maxValue - AbasePrev);
        increments_first = increments_next;
        cout << "Increments: " << increments_first.size() << endl;
    }
    cout <<  Abase;

}
