#include<bits/stdc++.h>
using namespace std; 

bool balancedSplitExists(vector<int>& arr){
  // [1 5 7 1]
  // leftSum = 14, rightSum = 0
  // [1 1 5 7]
  // leftSum = 7, rightSum = 7 => true
  
  int leftSum = 0, rightSum = 0;
  for(auto x : arr) leftSum += x;
  
  sort(arr.begin(), arr.end()); // O(n*logn)
  
  for(int i = arr.size()-1; i >= 0; i--) { // O(n)
    leftSum -= arr[i];
    rightSum += arr[i];
    if(leftSum == rightSum) {
      if(arr[i] != arr[i-1]) {
        return true;
      }
    }
  }
  
  return false;
}

/*
Using the idea of quickselect:
void partition(vector<int> &arr, long &s1, long total) {
  int pivot = arr[arr.size()-1];
  vector<int> low, high;
  long sum = 0;
  
  for(int i = 0; i < arr.size(); i++) {
    if(arr[i] <= pivot) {
      sum += arr[i];
      if(arr[i] < pivot) low.push_back(arr[i]);
    }
    else high.push_back(arr[i]);
  }
  
  if(2*(s1+sum) <= total) {
    s1 += sum;
    arr = high;
  }
  else arr = low;
}

bool balancedSplitExists(vector<int>& arr){
  if(arr.empty()) return true;
  
  long sum = 0;
  for(auto val : arr) sum += val;
  
  if(sum % 2 == 1) return false;
 
  long s1 = 0;
  while(!arr.empty()) {
    partition(arr, s1, sum);
    if(2*s1 == sum) return true;
  }
  
  return false;
}
*/

