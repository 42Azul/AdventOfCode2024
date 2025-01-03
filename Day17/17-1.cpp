#include <bits/stdc++.h>
using namespace std;



long A = 0;
long B = 0;
long C = 0;


long pointer = 0;


vector<int> code;


vector<int> printedValues;

long getValue(long value){
    if(value <= 3) return value;
    switch(value){
        case 4: return A;
        case 5: return B;
        case 6: return C;
        default: return -1;
    }

}

void advancePointer(){
    pointer++;
}

void executeCode() {
    // Keep stepping through until pointer >= code.size()
    while (pointer < code.size()) {
        // read opcode
        long codeOp = code[pointer];
        pointer++;

        // read operand
        if (pointer >= code.size()) {
            cerr << "Code was expecting an operand, but ended abruptly." << endl;
            exit(1);
        }
        long literal = code[pointer];
        long comboOp = getValue(literal);
        pointer++;

        // execute
        switch (codeOp) {
            case 0: // adv
                A = A >> comboOp;
                break;
            case 1: // bxl
                B ^= literal;
                break;
            case 2: // bst
                B = comboOp % 8;
                break;
            case 3: // jnz
                if (A != 0) {
                    pointer = literal;
                    continue; // jump re-checks while condition
                }
                break;
            case 4: // bxc
                B = B ^ C;
                break;
            case 5: // out
                printedValues.push_back(comboOp % 8);
                break;
            case 6: // bdv
                B = A >> comboOp;
                break;
            case 7: // cdv
                C = A >> comboOp;
                break;
            default:
                cerr << "Invalid opcode: " << codeOp << endl;
                exit(1);
        }
    }
}




int main(){
    cin.ignore(12);
    cin >> A;
    cin.ignore(12);
    cin >> B;
    cin.ignore(12);
    cin >> C;
    cin.ignore();
    cin.ignore(9);
    long value;
    while(cin>>value){
        code.push_back(value);
        cin.ignore();
    }

    cout << "Initial values for registers are: " << A << ", " << B << ", " << C << endl;

    executeCode();

    cout<< "Final values for registers are: A = " << A << " B = " << B << " C = " << C << endl;


    for(long i = 0; i <printedValues.size(); i++){
        if (i > 0) cout << ",";
        cout << printedValues[i];
    }
    cout << endl;
}
