// Distribute Candies

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  int result = 0 ; 
  int solve(Node* root){
      if(!root){
          return 0 ; 
      }
      
      int left = solve(root->left);
      int right = solve(root->right);
      
      result += abs(left) + abs(right);
      
      return root->data - 1 + left + right; 
  }
    int distCandy(Node* root) {
        solve(root);
        return result;
        
    }
};