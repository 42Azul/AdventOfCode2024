#include <bits/stdc++.h>
#include <map>
#include <queue>
#include <list>
using namespace std;


struct registerOperation {
    int opcode;
    string operand1;
    string operand2;
    string outputOperand;
    bool isReadyOp1 = false;
    bool isReadyOp2 = false;
};


map<string, int> opcodes = {{"AND", 0}, {"OR", 1}, {"XOR", 2}};


queue<registerOperation> doableOperations;
list<registerOperation> missingOperations;
map<string, int> operands;

int performOperation(registerOperation operation){
    switch(operation.opcode){
        case 0: return operands[operation.operand1] & operands[operation.operand2];
        case 1: return operands[operation.operand1] | operands[operation.operand2];
        case 2: return operands[operation.operand1] ^ operands[operation.operand2];
        default: return -1;
    }
}


string printOperation(registerOperation op){

    return "(" + op.operand1 + ", " + to_string(operands[op.operand1]) + ", " + op.operand2 + ", " + to_string(operands[op.operand2]) + ", " + op.outputOperand + ", " + to_string(operands[op.outputOperand]) + ") -> " + to_string(performOperation(op));

}


int main (){
    string line;
    string operand;
    int opValue;

    while(getline(cin, line) && line.size() > 0){
        istringstream is(line);
        is >> operand;
        operand.pop_back();
        is >> opValue;
        operands[operand] = opValue;
    }

    while(getline(cin, line)){
        istringstream is(line);
        registerOperation op;
        is >> op.operand1;
        string operandAsString;
        is >> operandAsString;
        op.opcode = opcodes[operandAsString];
        is >> op.operand2;
        is.ignore(4);
        is >> op.outputOperand;
        op.isReadyOp1 = operands.find(op.operand1) != operands.end();
        op.isReadyOp2 = operands.find(op.operand2)!= operands.end();
        if(op.isReadyOp1 && op.isReadyOp2){
            doableOperations.push(op);
        } else{
            missingOperations.push_back(op);
        }
    }

    while(!doableOperations.empty()){
        registerOperation op = doableOperations.front();
        doableOperations.pop();
        int result = performOperation(op);
        operands[op.outputOperand] = result;
        cout << op.outputOperand << " = " << operands[op.outputOperand] << endl;
        auto listIterator = missingOperations.begin();
        while(listIterator!= missingOperations.end()){
            registerOperation missingOp = *listIterator;
            if(missingOp.operand1 == op.outputOperand){
                missingOp.isReadyOp1 = true;
            }
            if(missingOp.operand2 == op.outputOperand){
                missingOp.isReadyOp2 = true;
            }
            if(missingOp.isReadyOp1 && missingOp.isReadyOp2){
                cout << "This operation is ready" << printOperation(missingOp) << endl;
                doableOperations.push(missingOp);
                missingOperations.erase(listIterator++);
            }else{
                *listIterator = missingOp;
                listIterator++;
            }
        }
    }

    map<int, bool> zetaValues;
    //Now we print all operands that are starting with z
    for(auto it = operands.begin(); it!= operands.end(); it++){
        if(it->first[0] == 'z'){
            string opStr = it->first;
            opStr = opStr.substr(1, opStr.size()-1);
            zetaValues[stoi(opStr)] = it->second;
        }
    }

    long value = 0;

    for(int i = zetaValues.size()-1; i >=0; i--){
        bool isThere = zetaValues[i];
        value = value << 1;
        value += isThere ? 1 : 0;
    }
    cout << value << endl;

    return 0;


}


