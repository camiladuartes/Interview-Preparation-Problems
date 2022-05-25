#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data; 
  Node* left ; 
  Node* right; 
  Node() {
    data = 0; 
    left = NULL; 
    right = NULL; 
  }
  Node(int data) {
    this->data = data; 
    this->left = NULL; 
    this->right = NULL; 
  }
};

// Add any helper functions you may need here
int visibleNodes(Node* root) {
  int visibNodes = 0;

  if(root == nullptr) return 0;
  queue<Node*> bfsQueue;
  bfsQueue.push(root);
  
  while(!bfsQueue.empty()) {
    int lenght = bfsQueue.size();
    for(int i = 0; i < lenght; i++) {
      Node* currNode = bfsQueue.front();
      if(i == 0) visibNodes++;
      if(currNode->left != NULL) bfsQueue.push(currNode->left);
      if(currNode->right != NULL) bfsQueue.push(currNode->right);
      bfsQueue.pop();
    }
  }
  
  return visibNodes;
}
