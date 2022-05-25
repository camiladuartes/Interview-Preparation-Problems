#include <bits/stdc++.h>
using namespace std;

vector <int> findPositions(vector <int> arr, int x) {
  vector<int> output;
  // to save the original indexes and perform queue operations
  queue<pair<int, int>> positions;
  for(int i = 0; i < arr.size(); i++) positions.push(make_pair(i+1, arr[i])); // O(n)
  
  // x iterations of the 3-step process
  for(int i  = 0; i < x; i++) { // O(x)    
    // pop x elements from the front of queue, finding the one with the largest value
    int largestVal = INT_MIN; int idxLargestVal = INT_MAX;
    vector<pair<int, int>> popped;
    for(int j = 0; j < x && !positions.empty(); j++) { // O(x)
      int currIdx = positions.front().first;
      int currVal = positions.front().second;
      if(currVal > largestVal) {
        largestVal = currVal;
        idxLargestVal = currIdx;
      }
      
      popped.push_back(positions.front());
      positions.pop();
    }
    
     // push the index of the greatest value (idxLargestVal) calculated previously
    output.push_back(idxLargestVal);
    
    // pop the largest value logically while put the elements back to the queue decrementing by 1 if it's positive
    for(pair<int, int> position : popped) {
      // I will not put back the largest val
      if(position.first != idxLargestVal) {
        positions.push((make_pair(position.first, position.second == 0 ? position.second : position.second-1)));
      }
    }
  }

  return output;
}

