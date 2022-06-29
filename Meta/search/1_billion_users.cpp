#include <bits/stdc++.h>
using namespace std;

// O(n * log2(1e9))
float numUsers(vector<float> growthRates, int t) {
  long double totalSum = 0;
  for(auto rate: growthRates) {
    totalSum += pow(rate, t);
  }
  return totalSum;
}

// O(n * log^2(m))
int getBillionUsersDay(vector <float> growthRates) {
  long double low = 1;
  long double high = 1;
  // log10(1e9) * (n * log2(1e9))
  while(numUsers(growthRates, high) <= 1e9) {
    high *= 10;
  }
  // Now numUsers(growthRates, low) <= 1e9 and numUsers(growthRates, high) >= 1e9
  
  // Binary Search. O(log2(1e9) * (n * log2(1e9))) = O(n * (log2(1e9)^2))
  while(low <= high) {
    //low = 1, high = 2
    long double mid = low + ((high-low)/2);
      
    if(numUsers(growthRates, mid) < 1e9)
      low = mid+1;
    // So numUsers(growthRates, high) >= 1e9
    else
      high = mid-1;
  }
  
  // Because numUsers(growthRates, high) >= 1e9
  if(numUsers(growthRates, floor(high)) >= 1e9)
    return floor(high);
  else
    return ceil(high);
}

