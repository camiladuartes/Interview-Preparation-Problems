#include <bits/stdc++.h>
using namespace std;

int maxMin(int k, vector<int> arr) {
    // arr [1,4,7,2] => [1,2,4,7]
    // k = 2, checking k by k: (1,2), (2,4), (4,7)
    int mimUnfairness = INT_MAX;
    sort(arr.begin(), arr.end());
    for(int i = 0; i <= arr.size()-k; i++) {
        if((arr[i+(k-1)] - arr[i]) < mimUnfairness)
            mimUnfairness = arr[i+(k-1)] - arr[i];
    }
    
    return mimUnfairness;
}
