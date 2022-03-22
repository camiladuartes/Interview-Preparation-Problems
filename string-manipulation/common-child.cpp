#include <bits/stdc++.h>
using namespace std;

int commonChild(string s1, string s2) {
    // Ex: HARRY and SALLY
    /*
    i=4, j=0
    dp[0][1]
    dp[1][0]
        i 0 1 2 3 4 5 
          H A R R Y
    j 0 S 0 0 0 0 0 0
      1 A 0 0 0 0 0 0
      2 L 0 0 1 1 1 1
      3 L 0 0 1 1 1 1
      4 Y 0 0 1 1 1 1
      5   0 0 0 0 0 2
    */
    vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
    
    for(int i = 0; i < s1.size(); i++){
        for(int j = 0; j < s2.size(); j++){
            if(s1[i] == s2[j]) dp[i+1][j+1] = 1 + dp[i][j];
            else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
        }
    }
    
    return dp[s1.size()][s2.size()];
}
