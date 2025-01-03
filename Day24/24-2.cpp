#include <bits/stdc++.h>
#include <map>
#include <queue>
#include <list>
#include <unordered_map>
using namespace std;


struct registerOperation {
    int opcode;
    string operand1;
    string operand2;
    string outputOperand;
};

string checkOperandsAndReturnOutput(registerOperation expected, registerOperation obtained){
    if(expected.opcode!=obtained.opcode ||( (expected.operand1!=obtained.operand1 || expected.operand2!=obtained.operand2) && (expected.operand1!=obtained.operand2 || expected.operand2!=obtained.operand1))){
        return "";
    }
    return obtained.outputOperand;
}


int AND = 0;
int OR = 1;
int XOR = 2;

map<string, int> opcodes = {{"AND", AND}, {"OR", OR}, {"XOR", XOR}};




bool isValidChain(unordered_map<string, map<int, registerOperation*>*> operations){
    string stringX = "x00";
    string stringZ = "z00";
    map<int, registerOperation*>* currentOperations;
    string remainder = "";
    string a, b, c;
    for(int i = 0; i<= 44; i++){

        stringX[1] = i /10 + '0';
        stringX[2] = i % 10 + '0';

        stringZ[1] = i /10 + '0';
        stringZ[2] = i % 10 + '0';

        currentOperations = operations[stringX];
        a = (*currentOperations)[XOR]->outputOperand;
        b = (*currentOperations)[AND]->outputOperand;
        cout << a << " " << b << " for i = " << i <<  endl;
        if(i==0){
             if(a!= stringZ) {
                 return false;
             }
             remainder = b;

        } else{
          //First we check a XOR remainder  
          currentOperations = operations[a];
          if(currentOperations== nullptr) return false;
          registerOperation expectedOperation = {XOR, a, remainder, ""};
          registerOperation* obtainedOperationPtr = (*currentOperations)[XOR];
          if(obtainedOperationPtr == nullptr || checkOperandsAndReturnOutput(expectedOperation, *obtainedOperationPtr)!= stringZ) {
            //cout << "Error, due to XOR Operation not being Z " << endl;
             return false;
          }
          //Then we check a AND b and store it into c
          expectedOperation = {AND, a, remainder, ""};
          obtainedOperationPtr = (*currentOperations)[AND];
          c = obtainedOperationPtr == nullptr ? "" :  checkOperandsAndReturnOutput(expectedOperation, *obtainedOperationPtr);
          if(c == ""){
             cout << "Error due to AND being null" << endl;
             return false;
          }

          //Then we check c OR remainder
          currentOperations = operations[c];
          if(currentOperations== nullptr) return false;
          expectedOperation = {OR, c, b, ""};
          obtainedOperationPtr = (*currentOperations)[OR];
          remainder = obtainedOperationPtr == nullptr ? "" : checkOperandsAndReturnOutput(expectedOperation, *obtainedOperationPtr);
          if(remainder == ""){
             return false;
          }

        }

    }

    //We also need to check the last remainder string equals z45
    return remainder == "z45";
}





string printOperation(registerOperation op){

    return "(" + op.operand1 + ", " + ", " + op.operand2 + + ", " + op.outputOperand;

}



void swapOutputOperand(vector<registerOperation*> &operations, vector<pair<int, int>> swaps){
    for(pair<int, int> swap: swaps){
        registerOperation* firstOperation = operations[swap.first];
        registerOperation* secondOperation = operations[swap.second];
        string tempOutput = firstOperation->outputOperand;
        firstOperation->outputOperand = secondOperation->outputOperand;
        secondOperation->outputOperand = tempOutput;
        cout << "swapped " << firstOperation->outputOperand << " " << secondOperation->outputOperand << endl;
    }
}






int main (){
    string line;
    string operand;
    int opValue;


    //We omit the input in the case of the second part of the problem
    while(getline(cin, line) && line.size() > 0){
    }



    unordered_map<string, map<int, registerOperation*>*> operations;

    vector<registerOperation*> listOfOperations;

    while(getline(cin, line)){
        istringstream is(line);
        registerOperation* op = new registerOperation();
        is >> op->operand1;
        string operandAsString;
        is >> operandAsString;
        op->opcode = opcodes[operandAsString];
        is >> op->operand2;
        is.ignore(4);
        is >> op->outputOperand;
        map<int, registerOperation*>* stringOperations;
        stringOperations = operations[op->operand1];
        if(stringOperations == nullptr){
            stringOperations = new map<int, registerOperation*>();
            operations[op->operand1] = stringOperations;
        }
        (*stringOperations)[op->opcode] = op;
        stringOperations = operations[op->operand2];
        if(stringOperations == nullptr){
            stringOperations = new map<int, registerOperation*>();
            operations[op->operand2] = stringOperations;
        }
        (*stringOperations)[op->opcode] = op;
        listOfOperations.push_back(op);
    }

    vector<pair<int,int>> swappingPos;
    bool foundValidChain = false;
    int n = listOfOperations.size();

    vector<int> invalidOperationsXOR;
    vector<int> invalidOperationsZ;

    map<int, bool> invalidOperationsMap;


    //First we find all that are ending in z, are either XOR (not being z45) or AND
    //Then we also take the ones that are not ending in
    for(int i = 0; i < n; i++){
        registerOperation* operation = listOfOperations[i];
        if(operation->outputOperand[0] == 'z' && operation->opcode != XOR && operation->outputOperand!= "z45"){
            cout << "Found invalid operation due to Z: " << i << endl;
            invalidOperationsZ.push_back(i);
            invalidOperationsMap[i] = true;
        }
        else if(operation->opcode == XOR && operation->outputOperand[0] != 'z' && operation->operand1[0] != 'x' && operation->operand2[0] != 'x'){
            cout << "Found invalid operation due to XOR: " << i << endl;
            invalidOperationsXOR.push_back(i);
            invalidOperationsMap[i] = true;
        }
    }


    int i1, i2;
    do{
        vector<pair<int,int> > pairWiseOperations;
        for(int l = 0; l < 3; l++) pairWiseOperations.push_back({invalidOperationsXOR[l], invalidOperationsZ[l]});

        for (i1 = 0; i1 < n && !foundValidChain; i1++) {
            if(invalidOperationsMap[i1]) continue;
            for (i2 = i1 + 1; i2 < n &&!foundValidChain; i2++) {

                                    if(invalidOperationsMap[i2]) continue;


                                    pairWiseOperations.push_back({i1, i2});
                                    //Print swapping pairs
                                    for(pair<int, int> swapPair: pairWiseOperations){
                                        cout << " " << swapPair.first << " " << swapPair.second << endl;
                                    }

                                    // Perform the swaps
                                    swapOutputOperand(listOfOperations, pairWiseOperations);

                                    // Check if chain is valid
                                    if (isValidChain(operations)) {
                                        // We found a valid chain
                                        foundValidChain = true;
                                        
                                        // Print or store the indices (i1..i8) any way you like
                                        cout << "Found valid chain with swaps:";
                                        set<string> pairWiseSet;
                                        for(pair<int, int> swap: pairWiseOperations){
                                            pairWiseSet.insert(listOfOperations[swap.first]->outputOperand);
                                            pairWiseSet.insert(listOfOperations[swap.second]->outputOperand);
                                        }
                                        for(string outputOp : pairWiseSet){
                                            cout << outputOp << ",";
                                        }
                                        cout << endl;
                                        break;
                                    }

                                    // Undo the swaps so we can try the next combination
                                    swapOutputOperand(listOfOperations, pairWiseOperations);
                                    pairWiseOperations.pop_back();
                                }
                            }
    } while(next_permutation(invalidOperationsZ.begin(), invalidOperationsZ.end()));
                        

    cout << foundValidChain << endl;


}


