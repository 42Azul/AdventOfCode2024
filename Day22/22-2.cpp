#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct fourTuple {
        long long first, second, third, fourth;

    bool operator==(const fourTuple& other) const {
        return first == other.first &&
               second == other.second &&
               third == other.third &&
               fourth == other.fourth;
    }
};

// Custom hash function for fourTuple
struct fourTupleHash {
    size_t operator()(const fourTuple& tuple) const {
        size_t h1 = hash<long long>()(tuple.first);
        size_t h2 = hash<long long>()(tuple.second);
        size_t h3 = hash<long long>()(tuple.third);
        size_t h4 = hash<long long>()(tuple.fourth);

        // Combine the hashes using XOR and bit-shifting
        return h1 ^ (h2 << 1) ^ (h3 << 2) ^ (h4 << 3);
    }
};

unordered_map<fourTuple, long long, fourTupleHash> fourTupleBenefits;




class Window : public vector<long long> {
private:
    int actualStart = 0; // Start index of the window
    int size;            // Size of the window
    int count = 0;       // Number of elements added so far

public:
    Window(int size) : vector<long long>(size), size(size) {}


    // Add a value to the window
    void add(long long value) {
        if (count < size) {
            (*this)[count] = value;
            count++;
        } else {
            // Slide and replace the oldest value
            long long oldValue = (*this)[actualStart];
            (*this)[actualStart] = value;
            actualStart = (actualStart + 1) % size;
        }
    }

    // Get the current window as a tuple of the differences
    fourTuple getAsDiffTuple() {
        if (count < size) {
            throw runtime_error("Window is not yet full.");
        }
        fourTuple result;
        result.first = (*this)[(actualStart + 1) % 5] - (*this)[actualStart];
        result.second = (*this)[(actualStart + 2) % 5] - (*this)[(actualStart + 1)%5];
        result.third = (*this)[(actualStart + 3) % 5] - (*this)[(actualStart + 2)%5];
        result.fourth = (*this)[(actualStart + 4) % 5] - (*this)[(actualStart + 3)%5];
        return result;
    }

    long long getLast(){
        return (*this)[(actualStart + size-1) % size] % 10;
    }

    bool isFull() const {
        return count == size;
    }
};




long long calculateNewSecretNumber(long long secretNumber){
    secretNumber = ((secretNumber << 6) ^ secretNumber) % (1 << 24);
    secretNumber = ((secretNumber >> 5) ^ secretNumber) % (1 << 24);
    secretNumber = ((secretNumber << 11) ^ secretNumber) % (1 << 24);
    return secretNumber;
}



int main(){
    long long input;
    long long total = 0;
    long prevInput = 0;
    while(cin >> input){
        cout << "Input: " << input << endl;
        Window window(5);
        unordered_set<fourTuple, fourTupleHash> seenTuple;
        for(int i = 0; i< 4; i ++){
            window.add(input%10);
            input = calculateNewSecretNumber(input);
        }
        for(int i = 0; i < 1996 ; i++){
            window.add(input%10);
            fourTuple currentTuple = window.getAsDiffTuple();
            input = calculateNewSecretNumber(input);
            if(seenTuple.contains(currentTuple)) continue;
            seenTuple.insert(currentTuple);
            long long currentMaxBenefit = fourTupleBenefits[currentTuple];
            currentMaxBenefit += window.getLast();
            fourTupleBenefits[currentTuple] = currentMaxBenefit;
            
        }

    }
    long long maxBenefit = -1;
    fourTuple maxFourTuple;
    for(auto tuple: fourTupleBenefits){
        if(maxBenefit <= tuple.second){
            maxBenefit = tuple.second;
            maxFourTuple = tuple.first;
        }
    }
    cout << maxBenefit << endl;
    cout << maxFourTuple.first << " " << maxFourTuple.second << " " << maxFourTuple.third << " " << maxFourTuple.fourth << endl;
    return 0;

}