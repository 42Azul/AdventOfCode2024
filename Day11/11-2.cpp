#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct Node{
    Node* left;
    Node* right;
    long value;
    long maxDepth;
    unordered_map<long, long> depthMap;
};


bool compareNodes(Node* a, Node* b){
    return a->value < b->value;
}


set<Node*, decltype(compareNodes)*> nodeSet(compareNodes);


long getDigits(long n){
    long count = 0;
    while(n > 0){
        n = n / 10;
        count++;
    }
    return count;
}


long int10Pow(long exponent){
    if(exponent == 0) return 1;
    else if (exponent%2!=0) return 10*int10Pow(exponent - 1);
    else {
        long halfExponent = int10Pow(exponent/2);
        return halfExponent*halfExponent;
    }
}

pair<long, long> getSplit(long n, long digits){
    long powerOf10 = int10Pow(digits/2);
    long firstPart = n / powerOf10;
    long secondPart = n % powerOf10;
    return make_pair(firstPart, secondPart);
}


void developNode(Node* node, long depth);

Node* findAndDevelopValue(long value, long depth){
    //cout << "Finding and developing value: " << value << " and depth: " << depth << endl;
    Node* newNode = new Node();
    newNode->value = value;
    newNode->maxDepth = 0;
    auto it = nodeSet.find(newNode);
    if(it!= nodeSet.end()){
        newNode = *it;
        developNode(newNode, depth);
    }
    else {
        developNode(newNode, depth);
        nodeSet.insert(newNode);
    }
    return newNode;
}


void developNode(Node* node, long depth){
    //cout << "Developing node with value: " << node->value << " and depth: " << depth << endl;
    if(node == NULL) return;
    if(node->depthMap[depth]!= 0) return;
    if(depth == 0){
        cout << "Leaf node with value: " << node->value << " and depth: " << depth << endl;
        node->depthMap[depth] = 1;
        return;
    }
    if(node->left != NULL || node->right != NULL){
            if(node->left != NULL) developNode(node->left, depth-1);
            if(node-> right != NULL) developNode(node->right, depth-1);
            node->maxDepth = depth;
            node->depthMap[depth] = node->left->depthMap[depth-1] + ((node->right==NULL) ? 0 : node->right->depthMap[depth-1]);
    }
    else{
        long value = node->value;
        if(value == 0){
                node->left = findAndDevelopValue(1, depth  - 1);
                node->depthMap[depth] = node->left->depthMap[depth-1];
        }
        else{
            long digits = getDigits(value);
            if(getDigits(value) %2 == 0){
                pair<long, long> split = getSplit(value, digits);
                Node* left = findAndDevelopValue(split.first, depth - 1);
                Node* right = findAndDevelopValue(split.second, depth - 1);
                node->left = left;
                node->right = right;
                node->depthMap[depth] = left->depthMap[depth-1] + right->depthMap[depth-1];
            }
            else{ 
                node->left = findAndDevelopValue(value*2024, depth - 1);
                node->depthMap[depth] = node->left->depthMap[depth-1];
            }
        }
    }
}



int main(){
    list<long> numbers;
    long number;
    while(cin>>number) numbers.push_back(number);
    auto it = numbers.begin();
    long res = 0;
    while(it!=numbers.end()){
        cout << "--------------------------------" << "VALUE FOR NUMBER " << *it << endl;
        Node* node = findAndDevelopValue(*it, 75);
        long depth = node->depthMap[75];
        cout << depth << endl;
        res += depth;
        it++;
    }
    cout << endl<< res << endl;   
}