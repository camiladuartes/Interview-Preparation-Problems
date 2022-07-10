#include <bits/stdc++.h>
using namespace std;

vector <int> findMinArray(vector <int> arr, int k) {
  // [5, 3, 1], k = 2
  // output = [1, 5, 3]
  // remainingSwaps = 0; currResultIdx = 0; currSmaller = 1; => [1,5,3]
  
  int remainingSwaps = k;
  int currResultIdx = 0;
  
  while(remainingSwaps > 0) {
    int currSmaller = INT_MAX;
    int currSmallerIdx;
    // O(k)
    for(int i = currResultIdx; i < arr.size(); i++) {
      if(i - currResultIdx > remainingSwaps) break;
      if(arr[i] < currSmaller) {
        currSmaller = arr[i];
        currSmallerIdx = i;
      }
    }
    
    remainingSwaps -= currSmallerIdx-currResultIdx;
    
    // O(k)
    // swap(arr[currResultIdx], arr[currSmallerIdx]);
    for(int i = currSmallerIdx; i > currResultIdx; i--) {
      swap(arr[i], arr[i-1]);
    }
    
    currResultIdx++;
  }
  
  return arr;
}

