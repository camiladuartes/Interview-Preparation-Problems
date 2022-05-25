#include <bits/stdc++.h>
using namespace std;

int hourglassSum(vector<vector<int>> arr) {
    int max_ = INT_MIN;
    int curr = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            curr = arr[i][j]
            + arr[i][j+1]
            + arr[i][j+2]
            + arr[i+1][j+1]
            + arr[i+2][j]
            + arr[i+2][j+1]
            + arr[i+2][j+2];
            if(curr > max_)
                max_ = curr;
            curr = 0;
        }
    }
    return max_;
}

