#include <bits/stdc++.h>
using namespace std;

bool canGetExactChange(int targetMoney, vector<int>& denominations){
  if(targetMoney == 0) return true;
  if(targetMoney < 0) return false;
  for(int i = 0; i < denominations.size(); i++) {
    // instead of denominations, pass only denominations[i:], because if we go to
    // the next iteration it's because the last denomination isn't in the solution
    vector<int> subvec(denominations.begin()+i, denominations.end());
    if(canGetExactChange(targetMoney - denominations[i], subvec))
      return true;
  }
  return false;
  
  /*
  // Dynamic Programming => O(size_of_denom. * targetMoney)
  // targetMoney = 12, denominations = [1,2,5]
  // countSum => [1,1,2,2,3,3,4,4,5,5,6,6,7]  
  vector<int> countSum(targetMoney+1);
  countSum[0] = 1;
  
  for(auto coin : denominations) {
    for(int i = 1; i < countSum.size(); i++) {
      if(i >= coin) {
        countSum[i] += countSum[i - coin];
      }
    }
  }
  if(countSum[targetMoney] != 0) return true;
  return false;
  */
  
  /*
  // Exponential (for each denomications, the function it's called size_of_denom. times) --> size_of_denom^size_of_denom
  if(targetMoney == 0) return true;
  if(targetMoney < 0) return false;
  for(auto d : denominations) {
    if(canGetExactChange(targetMoney-d, denominations))
      return true;
  }
  return false;
  */
}
