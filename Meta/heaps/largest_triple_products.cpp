#include <bits/stdc++.h>
using namespace std;

vector <int> findMaxProduct(vector <int> arr) {
  vector<int> output;
  // min heap
  priority_queue<int, vector<int>, greater<int>> maxK;
  
  for(int i = 0; i < arr.size(); i++) {
    if(i < 2) {
      output.push_back(-1);
      maxK.push(arr[i]);
    }
    else {
      if(i == 2) maxK.push(arr[i]);
      else {
        if(maxK.top() < arr[i]) {
          maxK.pop();
          maxK.push(arr[i]);
        } 
      }
      int value1 = maxK.top();
      maxK.pop();
      int value2 = maxK.top();
      maxK.pop();
      int value3 = maxK.top();
      maxK.pop();
      output.push_back(value1 * value2 * value3);
      maxK.push(value1);
      maxK.push(value2);
      maxK.push(value3);
    }
  }
  
  return output;
}
