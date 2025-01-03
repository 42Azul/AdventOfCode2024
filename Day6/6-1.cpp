#include <bits/stdc++.h>
using namespace std;



void rotate(long &dx, long &dy){
    long temp = dx;
    dx = -dy;
    dy = temp;
}

int main() {

    string line;
    vector<vector<int> > map;
    long x, y;

    while(getline(cin, line)){
        istringstream iss(line);
        vector<int> row;
        char c;
        while(iss >>  c){
            row.push_back(c == '#');
            if(c == '^'){
                x = row.size()  - 1;
                y = map.size();
            }
        }
        map.push_back(row);
    }

    long dx = 0, dy = -1;
    cout << "Start: (" << x << "," << y << ")" << endl;
    long long count = 0;
    while(x < map.size() && y < map.size() && x>=0 && y>=0){
        cout << x << " " << y << endl;
        if(map[y][x] == 1){
            y = y - dy;
            x = x - dx;
            rotate(dx, dy);
        } else if (map[y][x] == 0){
            map[y][x] = 2;
            count++;
        }
        x += dx;
        y += dy;
    }
    cout << count << endl;

    return 0;


}