#include <bits/stdc++.h>
using namespace std;


typedef vector<vector<int>> vvi;



int reachableNinesRecursive(vvi &matrix, int x, int y, int previousValue) {
    if(x < 0 || y < 0 || y >= matrix.size() || x >= matrix[0].size()  || previousValue + 1 != matrix[y][x]) return 0;
    int value = matrix[y][x];
    matrix[y][x] = -1;  // Mark the cell as visited to avoid revisiting.
    if(value == 9) return 1;  // Reached a 9, so return 1.
    return (reachableNinesRecursive(matrix, x-1, y, value) + reachableNinesRecursive(matrix, x+1, y,value) + reachableNinesRecursive(matrix, x, y-1, value) + reachableNinesRecursive(matrix, x, y+1,value));
}


int reachableNines(vvi matrix, int startX, int startY) {
    long result = reachableNinesRecursive(matrix, startX, startY, -1);
    cout << "Sum: " << result << endl;
    return result;

}



int main(){
    string line;
    vvi matrix;
    set<pair<int, int>> startingZeros;
    long result = 0;
    int x, y;
    y = 0;
    while(getline(cin, line)){
        istringstream iss(line);
        char number;
        vector<int> row;
        x = 0;
        while(iss >> number){
            row.push_back(number - '0');
            if (number == '0') startingZeros.insert({y, x});
            x++;
        }
        matrix.push_back(row);
        y++;
    }
    for(pair<int, int> zero : startingZeros){
        cout << "Starting at: (" << zero.second << ", " << zero.first << ")" << endl;
        long toSum =  reachableNines(matrix, zero.second, zero.first);
        result += toSum;
    }
    cout << result << endl;
    
}