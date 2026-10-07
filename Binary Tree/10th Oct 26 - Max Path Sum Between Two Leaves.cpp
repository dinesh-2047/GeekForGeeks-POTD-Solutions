// Max Path Sum Between Two Leaves

/* Node Structure
class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = nullptr;
        right = nullptr;
    }
}
*/

class Solution {
  public:
  int result = -1e9 ; 
  int solve(Node* root){
      if(!root) return -1e9; 
      
      if(!root->left && !root->right) return root->data; 
      
      int left = solve(root->left);
      int right = solve(root->right);
      
      if(left != -1e9 && right != -1e9){
          result = max({result, left + root->data + right});
      }
      return max(left + root->data, right + root->data);
  }
    int maxPathSum(Node *root) {
        solve(root); 
        return result == -1e9 ? -1: result; 
    }
};