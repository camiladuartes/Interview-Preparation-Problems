#include <bits/stdc++.h>
using namespace std;

long countTriplets(vector<long> arr, long r) {
    map<long, long> pref;
    map<long, long> suff;
    
    for(auto a : arr)
        suff[a]++;
    
    long ans = 0;
    for(int i = 0; i < arr.size(); i++) {
        suff[arr[i]]--;
        if(arr[i] % r == 0) {
            ans += pref[arr[i]/r] * suff[arr[i]*r];
        }
        pref[arr[i]]++;
    }
    
    return ans;
}

