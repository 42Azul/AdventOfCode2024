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
    long long count = 0;
    while (!pqIzq.empty() &&!pqDer.empty()) {
        if( pqIzq.top() > pqDer.top()) {
            long long specficTop = pqIzq.top();
            while(!pqIzq.empty() && pqIzq.top() == specficTop) {
                suma += pqIzq.top() * count;
                pqIzq.pop();
            }
            count = 0;

        } else{
            count = count + ( pqIzq.top() == pqDer.top());
            pqDer.pop();
        } 
    }
    if (count > 0){
        suma += pqIzq.top() * count;
    }

    cout << suma << endl;

}
    
 
