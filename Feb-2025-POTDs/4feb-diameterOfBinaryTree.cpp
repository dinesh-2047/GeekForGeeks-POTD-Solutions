// Diameter of binary tree 

class Solution {
  public:
  int solve(Node* root, int& ans){
      if(root == nullptr) return 0 ; 
      
      int left = solve(root->left, ans);
      int right = solve(root->right , ans);
      
      ans = max(ans , left +right);
      
      return max(left, right)+1;
  }
    int diameter(Node* root) {
       if(root == nullptr) return 0 ; 
       
       int ans = INT_MIN;
       solve(root, ans);
       return ans;
    }
};