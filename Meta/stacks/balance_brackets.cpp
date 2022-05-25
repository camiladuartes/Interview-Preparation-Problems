#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string s) {
  // stack: LIFO
  stack<char> chars;
  for(auto c : s) {
    if(c == '(' or c == '{' or c == '[') chars.push(c);
    else {
      // there's a change to be a balanced string until now
      if((c == ')' and chars.top() == '(') ||
         (c == ']' and chars.top() == '[') ||
         (c == '}' and chars.top() == '{'))
        chars.pop();
      // unmatching brackets already found
      else return false;
    }
  }
  
  if(chars.empty()) return true;
  return false;
}
