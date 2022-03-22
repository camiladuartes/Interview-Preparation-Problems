#include <bits/stdc++.h>
using namespace std;

int minimumAbsoluteDifference(vector<int> arr) {
    int minDif = INT_MAX;
    int left, right;
    
    sort(arr.begin(), arr.end());
        
    for(int i = 0; i < arr.size()-1; i++) {
        left = i, right = i+1;
        int absVal = abs(arr[left]-arr[right]);
        minDif = min(absVal, minDif);
    }
    
    return minDif;
}
