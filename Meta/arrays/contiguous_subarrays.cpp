#include <bits/stdc++.h>
using namespace std;

vector <int> CountSubarrays(vector <int> arr) {
  // O(n)
  vector<int> returnArr;
  
  stack<int> leftIdxMax;
  leftIdxMax.push(0);
  returnArr.push_back(1);
  for(int i = 1; i < arr.size(); i++) {
    while(!leftIdxMax.empty() && arr[leftIdxMax.top()] < arr[i]) leftIdxMax.pop();
    if(leftIdxMax.empty()) returnArr.push_back(i+1);
    else returnArr.push_back(i-leftIdxMax.top());
    leftIdxMax.push(i);
  }
  
  /* example only for the right side:
   * stack = [4]; i = 3; arr[i] = 6 < arr[4] => pop() => [(5-i-1)] = [(5-3-1)] = [1]
   * stack = [3]; i = 2; arr[i] = 1 !< arr[3] => [(stack-i-1)]
   * ...
   */
  stack<int> rightIdxMax;
  rightIdxMax.push(arr.size()-1);
  for(int i = arr.size()-2; i >= 0 ; i--) {
    while(!rightIdxMax.empty() && arr[rightIdxMax.top()] < arr[i]) rightIdxMax.pop();
    if(rightIdxMax.empty()) returnArr[i] += (arr.size()-i-1);
    else returnArr[i] += (rightIdxMax.top()-i-1);
    rightIdxMax.push(i);
  }
  
  /*
  // O(n^2)
  vector<int> returnArr;
  for(int i = 0; i < arr.size(); i++) {
    int counter = 1;
    for(int j = i-1; j >= 0; j--) {
      if(arr[j] <= arr[i]) counter++;
      else break;
    }
    for(int j = i+1; j < arr.size(); j++) {
      if(arr[j] <= arr[i]) counter++;
      else break;
    }
    returnArr.push_back(counter);
  }
  */
  
  return returnArr;
}
