#include <bits/stdc++.h>
using namespace std;

int minLengthSubstring(string s, string t) {
  // s = "abbaacdbcab"; t = "abc"
  // baac, acdb, bca, cab => 3
  
  // Two pointers approach
  int left = 0, right = 0;
  unordered_map<char, int> tMap;
  for(auto c : t) tMap[c]++;
  
  unordered_map<char, int> sMap;
  int minLen = -1;
  int requiredSize = 0; // Goal: reach s size
  
  // Go till the end of the s string
  while(right < s.size()) {
    char c = s[right];
    sMap[c]++;
    
    if(tMap.find(c) != tMap.end()) {
      if(tMap[c] == sMap[c]) {
        requiredSize++;
      }
    }
    
    // While it has all of the characters
    while(requiredSize == tMap.size() && left < right) {
      // Update min length
      if(minLen == -1 || minLen > (right-left+1)) {
        minLen = right-left+1;
      }

      char lChar = s[left];
      sMap[lChar]--;
      if(tMap.find(lChar) != tMap.end()) {
        if(tMap[lChar] > sMap[lChar]) {
          requiredSize--;
        }
      }
      left++;
    }
    
    right++;
  }
  
  return minLen;
}

