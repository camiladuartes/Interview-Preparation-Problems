#include <bits/stdc++.h>
using namespace std;

// s = "abcdb"
// t = "adcbe"
// output = 4
// counterDiff = 2
// {(b,2), (d,1)}
// {(d,1), (b,1), (e,1)}
// counterEqual == 2 => break => return (s.size()-counterDiff)+2
// otherwise => (s.size()-counterDiff)

// s = "mno"
// t = "mno"
// output = 1
// If there's 0 counterDiff, decrease answer by 2:
// counterDiff = 0 => return s.size()-2

// s = "mon"
// t = "mno"
// output = 3
// {(o,1),(n,2)}
// {(n,1),(o,2)}
// counterDiff = 2 => return (s.size()-counterDiff)+2

int matchingPairs(string s, string t) {
  int counterDiff;
  // <char, counter of this char in a wrong place>
  map<char, int> sDiff;
  map<char, int> tDiff;
  int n = s.size();
  
  for(int i = 0; i < n; i++) {
    if(s[i] != t[i]) {
      sDiff[s[i]]++;
      tDiff[t[i]]++;
    }
  }
  counterDiff = sDiff.size();
  
  // Counter of char in s and t that are equal but not on the same indexes
  int counterEqual = 0;
  if(counterDiff == 0) return (n - 2);
  else {
    for(auto it = sDiff.begin(); it != sDiff.end(); it++) {
      if(counterEqual == 2) return n-counterDiff+2;
      
      char currChar = (*it).first;
      int currFreq = (*it).second;
      if(tDiff.find(currChar) != tDiff.end()) {
        if(currFreq > 1) {
          if(tDiff[currChar] > 1)
            return n-counterDiff+2;
        }
        else {
          counterEqual++;
        }
      }
    }
  }
  
  if(counterEqual == 2) return n-counterDiff+2;
  return n-counterDiff;
}

