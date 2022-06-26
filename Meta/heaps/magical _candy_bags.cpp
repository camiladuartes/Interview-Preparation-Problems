#include <bits/stdc++.h>
using namespace std;

int maxCandies(vector <int> arr, int k) {
  priority_queue<int> heap;
  
  for(auto val : arr)
    heap.push(val);
  
  int counter = 0;
  
  for(int i = 0; i < k; i++) {
    int top = heap.top();
    counter += top;
    
    heap.pop();
    heap.push(floor(top/2));
  }
  
  return counter;
}

