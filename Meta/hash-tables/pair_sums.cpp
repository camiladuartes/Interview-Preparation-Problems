#include <bits/stdc++.h>
using namespace std;

int numberOfWays(vector<int>& arr, int k) {
  // 1 2 3 4 3; k = 6
  // {1:1, 2:1, 3:2, 4:1}
  
  // O(n)
  unordered_map<int, int> numCountMap;
  for(int i = 0; i < arr.size(); i++) {
    // making a map with the number of occurrencies of each value
    numCountMap[arr[i]]++;
  }
  
  int count = 0;
  for(int i = 0; i < arr.size(); i++) {
    count += numCountMap[k - arr[i]];
    // if I'm the half of k, decrease count so I won't be counted  
    if((k - arr[i]) == arr[i]) count--;
  }
  
  // as every pair is counted twice
  return count/2;
}

