// Closest Neighbour in BST

class Solution {
  public:
  int ans;
  void solve (Node *root, int k){
      if(root==nullptr) return;
      solve(root->left,k);
      if(root->data <= k ) ans = root->data;
      solve(root->right, k);
  }
  
    int findMaxFork(Node* root, int k) {
        ans = -1;
         solve (root, k);
         return ans;
        
    }
};