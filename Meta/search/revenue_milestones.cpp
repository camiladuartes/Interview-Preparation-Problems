#include <bits/stdc++.h>
using namespace std;

vector <int> getMilestoneDays(vector <int> revenues, vector<int> milestones) {
  unordered_map<int, int> milestonesIdxs;
  for(int i = 0; i < milestones.size(); i++) {
    milestonesIdxs[milestones[i]] = i;
  }
  
  sort(milestones.begin(), milestones.end()); // n * logn
  vector<int> output(milestones.size(), -1);
  int milestoneIndex = 0, sum = 0;
  
  for(int i = 0; i < revenues.size(); i++) {
    sum += revenues[i];
    if(sum >= milestones[milestoneIndex]) {
      while(sum >= milestones[milestoneIndex] && milestoneIndex < milestones.size()) {
        output[milestonesIdxs[milestones[milestoneIndex]]] = i+1;
        milestoneIndex++;
      }
      if(milestoneIndex == milestones.size()) break;
    }
  }
  
  return output;
}



