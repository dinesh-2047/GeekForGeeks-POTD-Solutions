// Construct a Full Binary Tree

/* Structure of Binary Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
  int n; 
  int i = 0 ; 
  Node* solve(int  st, int end , vector<int> &pre, vector<int> &preMirror ){
      if(st > end || i >= n ) return nullptr; 
      
      if(i == n - 1 || st == end){
          Node* temp = new Node(pre[i]);
          i++;
          return temp; 
      }
      
      Node* root = new Node(pre[i]);
      i++;
      for(int j = st; j  <= end; j++){
          if(pre[i] == preMirror[j]){
              root->left = solve(j, end, pre, preMirror);
              root->right = solve(st + 1, j - 1, pre, preMirror);
              break; 
          }
      }
    return root;
  }
    Node *constructBinaryTree(vector<int> &pre, vector<int> &preMirror) {
        n = pre.size();
       return solve(0, n -1, pre, preMirror);
        
    }
};