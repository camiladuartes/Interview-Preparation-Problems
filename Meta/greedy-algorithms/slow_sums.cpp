#include <bits/stdc++.h>
using namespace std;

int getTotalTime(vector <int> arr) {
  // Easier way: using a max heap
  
  // [4,2,1,3]
  // [1,2,3,4]
  // stack: [4,3,2,1]
  // stack: [7,2,1], p += 7
  // stack: [9,1], p += 9
  // stack: [10], p += 10
  // 26
  
  // [1,2,3,4,5]
  // stack: [5,4,3,2,1]
  // stack: [9,3,2,1], p += 9
  // stack: [12,2,1], p += 12
  // stack: [14,1], p += 14
  // stack: [15], p += 15
  // 50
  
  sort(arr.begin(), arr.end()); // n*logn
  
  stack<int> auxStack;
  for(int i = 0; i < arr.size(); i++) auxStack.push(arr[i]);
  
  int penalty = 0, currSum = 0;
  
  while(auxStack.size() > 1) {
    currSum = 0;
    for(int i = 0; i < 2; i++) {
      currSum += auxStack.top();
      auxStack.pop();
    }
    auxStack.push(currSum);
    penalty += currSum;
  }
  
  return penalty;
}

