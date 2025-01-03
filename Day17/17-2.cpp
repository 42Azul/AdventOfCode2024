#include <bits/stdc++.h>
using namespace std;



unsigned long long int A = 0;
unsigned long long int B = 0;
unsigned long long int C = 0;

vector<unsigned long long int> code;




int main(){
    code = {2,4,1,3,7,5,1,5,0,3,4,2,5,5,3,0};
    //We made the manual process up to the third character, j = 2
    vector<unsigned long long int> increments_first = {703,373,3,61,1,66,520,1024,373,3,61,1,66,438,82,1024,373,3,61,1,66,520,353,4,60,4,1,59,64,64,64,64,64,64,64,5,59,31,33,64,64,64,64,84,3,61,1,66,438,82, 321};

    //unsigned long long int Abase = 35184372088832;

    bool isEqual = false;
    unsigned long long int Abase, AbasePrev;

    for(long long unsigned int digit = 3; digit <= code.size() && isEqual==false; digit++){
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
