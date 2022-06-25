#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int val;
  vector<Node*> children;
  
  Node() {
    val = 0;
    children = vector<Node*>();
  }
  
  Node(int _val) {
    val = _val;
    children = vector<Node*>();
  }
  
  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

struct Query {
  int u; 
  char c; 
};

vector<int> countOfNodes(Node* root, vector<Query> queries, string s) {
  if(root == nullptr) return {};
  
  vector<int> queriesRes;
  
  for(auto q : queries) {
    // BFS idea
    Node *auxRoot = root;
    int resCounter = 0;
    // (u found, level)
    pair<bool, int> found = {false, -1}; 
    
    // (root, level)
    queue<pair<Node*, int>> auxQueue;
    auxQueue.push({auxRoot, 1});
    
    while(!auxQueue.empty()) {
      Node* currNode = auxQueue.front().first;
      int level = auxQueue.front().second;
      
      auxQueue.pop();

      if(currNode->val == q.u) {
        found = {true, level};
        // clearing queue
        queue<pair<Node*, int>> emptyQueue;
        auxQueue = emptyQueue;
      }
      
      if(found.first) {
        if(s[currNode->val - 1] == q.c) {
          resCounter++;
        }
      }
      
      for(auto child : currNode->children) {
        auxQueue.push({child, level+1});
      }
    }
    
    queriesRes.push_back(resCounter);
  }
  
  return queriesRes;
}

