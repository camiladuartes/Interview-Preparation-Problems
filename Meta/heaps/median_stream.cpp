#include <bits/stdc++.h>
using namespace std;

vector <int> findMedian(vector <int> arr) {
  for(auto i : arr) cout << i << " ";  
  // [2 4 7 1 5 3]
  // min_heap [7 5 4]
  // max_heap [1 2 3]
  // result [2 4 3 4 ]
  
  // O(n*logn)?
  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;
  vector<int> result;
  
  for(int i = 0; i < arr.size(); i++) {
    // Even index, so odd number of values
    // I will have the current smallest and put in the greatests ones
    if((i % 2) == 0) {
      minHeap.push(arr[i]);
      maxHeap.push(minHeap.top());
      minHeap.pop();
      result.push_back(maxHeap.top());
    }
    // I will have the current greater and put in smallests ones
    else {
      maxHeap.push(arr[i]);
      minHeap.push(maxHeap.top());
      maxHeap.pop();
      result.push_back(abs((maxHeap.top() + minHeap.top())/2));
    }
  }
  
  return result;
}

