#include <bits/stdc++.h>
using namespace std;

struct sides{
  long long a;
  long long b;
  long long c;
};

sides sortSides(sides side) {
  if(side.a > side.c)
    swap(side.a, side.c);
  
  if(side.a > side.b)
    swap(side.a, side.b);
  // Now the smallest element is in the beggining
  
  if(side.b > side.c)
    swap(side.b, side.c);
  /*
  // OR:
  vector<long long> vec{side.a, side.b, side.c};
  sort(vec.begin(), vec.end());
  side.a = vec[0];
  side.b = vec[1];
  side.c = vec[2];
  */
  return side;
}

int countDistinctTriangles(vector <sides> arr) {
  // [[7,6,5],[5,7,6],[8,2,9],[2,3,4],[2,4,3]] =>
  // [[5,6,7],[5,6,7],[2,8,9],[2,3,4],[2,3,4]] =>
  // {{5,{6,7}}, {2,{8,9}}, {2,{3,4}}}
  
  if(arr.size() == 0) return 0;
  
  for(int i = 0; i < arr.size(); i++) {
    arr[i] = sortSides(arr[i]);
  }
  
  set<pair<long long, pair<long long, long long>>> distTrian;
  for(auto tri : arr) {
    distTrian.insert({tri.a, {tri.b, tri.c}});
  }
  
  return distTrian.size();
}

