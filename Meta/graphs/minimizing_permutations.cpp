#include <bits/stdc++.h>
using namespace std;

int minOperations(vector <int> arr) {
  string start;
  for(auto val : arr) start += to_string(val);
  
  queue<string> q;
  q.push(start);
  
  unordered_set<string> visited;
  visited.insert(start);
  
  // idx is gonna have the current number of operations
  for(int numOp = 0; !q.empty(); numOp++) {
    // walk through the current graph breadth (each node represents a permutation)
    for(int breadthSize = q.size(); breadthSize > 0; breadthSize--) {
      string currStr = q.front();
      q.pop();
      if(is_sorted(currStr.begin(), currStr.end())) return numOp;
      
      for(int i = 0; i < arr.size(); i++) {
        // i+2 (instead of i+1) and <=(instead of <) because of the reverse function
        for(int j = i+2; j <= arr.size(); j++) {
          reverse(currStr.begin()+i, currStr.begin()+j);
          // only add it to the queue if it's not visited yet
          if(visited.insert(currStr).second) q.push(currStr);
          // reverse it back to find another permutations of currStr
          reverse(currStr.begin()+i, currStr.begin()+j);
        }
      }
    }
  }
  
  return 0;
  
  /*
  // MLE: O(N! * N^2) -> N! permutations and o(N) reverse inside a for loop of o(N)
  string start = "";
  for(auto val : arr) start += to_string(val);
  
  sort(arr.begin(), arr.end());
  string target = "";
  for(auto val : arr) start += to_string(val);

  // <currentString, numOperations>
  queue<pair<string, int>> bfsQueue; 
  bfsQueue.push(make_pair(start, 0));
  if(start == target) return 0;
  
  // Each permutation is like a node in a graph
  // I discover the sons of the current node, remove the current node from the queue and go to the next value on queue (bfs)
  while(!bfsQueue.empty()) {
    pair<string, int> currPair = bfsQueue.front();
    string currVal = currPair.first;
    bfsQueue.pop();
    for(int i = 2; i <= arr.size(); i++) {
      string aux = currVal;
      
      reverse(aux.begin(), aux.begin()+i);
      
      if(aux == target) return currPair.second+1;
      // push sun to queue to try permutation on him after
      else bfsQueue.push(make_pair(aux, currPair.second+1));
    }
  }
  */
}

