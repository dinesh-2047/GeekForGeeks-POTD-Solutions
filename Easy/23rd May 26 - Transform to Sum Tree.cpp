// Transform to Sum Tree


/* Structure for Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
  int solve(Node* root){
      if(!root) return 0; 
    
      
      int l = solve(root->left);
      int r = solve(root->right);
      
      int old_val = root->data; 
      
      root->data = l + r; 
      
      return root->data + old_val; 
      
      
  }
    void toSumTree(Node *root) {
        solve(root);
       
       
        
    }
};