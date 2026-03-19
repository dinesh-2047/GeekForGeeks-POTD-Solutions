// Largest BST

class Info{
    public:
    bool isBST; 
    int size; 
    int mini ; 
    int maxi ; 
};


class Solution {
  public:
  int result = 0 ; 
  Info solve(Node *root){
      if(!root){
          return {true, 0, INT_MAX,INT_MIN};
      }
      
      auto left = solve(root->left);
      auto right = solve(root->right);
      
      if(left.isBST && right.isBST && root->data > left.maxi && root->data < right.mini){
          int currSize = left.size + right.size + 1; 
          
          result = max(result, currSize);
          
          return {true, currSize, min(root->data, left.mini), max(root->data, right.maxi) };
      }
      
      return {false, 0 , 0, 0};
  }
  
  
    int largestBst(Node *root) {
        solve(root);
        return result; 
        
    }
};