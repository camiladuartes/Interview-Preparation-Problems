#include <bits/stdc++.h>
using namespace std;

int minOverallAwkwardness(vector <int> arr) {
  // O(n*logn): Constructive solution
  // Example: [1 2 3 4 5 6 7 8 9] turns into:
  //      1
  //   3 ___ 2 
  // 5  /   \  4
  // 7  \___/  6
  //    9   8
  // If I just order it, the first position with the last one
  // won't have the smaller difference as the others,
  // so we can make it be at most two positions mixed from sorted way(best way).
  // In order to do it, we make our list be: [1 3 5 7 9 8 6 4 2], checking
  // value from index i with index i-2
  
  sort(arr.begin(), arr.end());
  int minAwkw = 0;
  for(int i = 2; i < arr.size(); i++) {
    minAwkw = max(minAwkw, abs(arr[i] - arr[i-2]));
  }
  
  return minAwkw;
}

