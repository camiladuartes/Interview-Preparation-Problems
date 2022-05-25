#include <bits/stdc++.h>
using namespace std;

vector<int> rotLeft(vector<int> a, int d) {
    if(a.size() == d) return a;
    queue<int> qa;
    for(auto x : a) {
       qa.push(x);
    }
    for(int i = 0; i < d; i++) {
        int curr = qa.front();
        qa.pop();
        qa.push(curr);
    }
    vector<int> b;
    while(!qa.empty()) {
        b.push_back(qa.front());
        qa.pop();
    }
    return b;
}

