#include <bits/stdc++.h>
using namespace std;

int luckBalance(int k, vector<vector<int>> contests) {
    vector<pair<int,int>> luckImp;
    int maxLuck = 0, numImpContests = 0;
    for(int i = 0; i < contests.size(); i++) {
        luckImp.push_back(make_pair(contests[i][0], contests[i][1]));
    }
    // ordered by key (luck)
    sort(luckImp.begin(), luckImp.end());
    
    for(int i = luckImp.size()-1; i >= 0; i--) {
        if(luckImp[i].second == 0) maxLuck += luckImp[i].first;
        else {
            if(numImpContests < k) {
                maxLuck += luckImp[i].first;
                numImpContests++;
            } else {
                maxLuck -= luckImp[i].first;
            }
        }
    }
    
    return maxLuck;
}
