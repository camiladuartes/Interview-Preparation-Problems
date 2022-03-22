#include <bits/stdc++.h>
using namespace std;

int getMinimumCost(int k, vector<int> c) {
    // c = [1,2,3,4]
    // k = 2
    // 2 * (1+1) = 4
    // 1 * (1+1) = 2
    // minimum cost = 3 + 4 + 4 + 2 = 13
    
    int numPurshases = 0, minCost = 0, numRounds = 0;
    sort(c.begin(), c.end());
    for(int i = c.size()-1; i >= 0; i--) {
        minCost += c[i] * (1+numRounds);
        if((numPurshases+1) % k == 0) {
            numRounds += 1;
        }
        numPurshases++;
    }
    
    return minCost;
}
