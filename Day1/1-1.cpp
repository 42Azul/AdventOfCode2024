#include  <bits/stdc++.h>


using namespace std;

int main() {

    priority_queue<long long> pqIzq;
    priority_queue<long long> pqDer;
    

    long long izq, der;
    while(cin >> izq >> der) {

        pqIzq.push(izq);
        pqDer.push(der);

    }

    long long suma = 0;
    while (!pqIzq.empty() &&!pqDer.empty()) {
        suma += abs(pqIzq.top() - pqDer.top());
        pqIzq.pop();
        pqDer.pop();
    }

    cout << suma << endl;

}
    
 
