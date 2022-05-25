#include <bits/stdc++.h>
using namespace std;

string findEncryptedWord(string s) {
  string r = "";
  int mid = s.length()/2;
  if(s.length() % 2 == 0) mid--;
  
  // abcdefg
  // mid = 5/2 = 2
  // 7-(mid+1) = 7-3 = 4
    
  r += s.substr(mid, 1);
  
  if(mid > 0) r += findEncryptedWord(s.substr(0, mid));
  
  if(mid < s.length()-1) r += findEncryptedWord(s.substr(mid+1, s.length()-(mid+1)));
  
  return r;
}

