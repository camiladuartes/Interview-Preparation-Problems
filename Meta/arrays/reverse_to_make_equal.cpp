#include<bits/stdc++.h>
using namespace std; 

bool areTheyEqual(vector<int>& array_a, vector<int>& array_b){
  map<int,int> aFreq;
  map<int,int> bFreq;
  
  for(auto num : array_a) {
    aFreq[num]++;
  }
  
  for(auto num : array_b) {
    bFreq[num]++;
  }
  
  for(auto it = aFreq.begin(); it != aFreq.end(); it++) {
    int key = (*it).first;
    int keyFreq = (*it).second;
    if(bFreq.find(key) == bFreq.end()) return false;
    else {
      if(bFreq[key] != keyFreq) return false;
    }
  }
  
  return true;
}

