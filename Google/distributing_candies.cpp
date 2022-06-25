#include <bits/stdc++.h>
using namespace std;

int distributeCandies(vector<int>& candyType) {
    int target = candyType.size()/2;
    map<int, int> typeFreq;
    for(auto candyTp : candyType) typeFreq[candyTp]++;
    
    int freqMapSize = typeFreq.size();
    
    return (freqMapSize >= target ? target : freqMapSize);
}