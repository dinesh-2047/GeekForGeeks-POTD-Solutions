// Minimum Absolute Difference In BST

/* Binary Tree Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; 
*/

class Solution {
  public:
  int result ; 
  Node* prev = nullptr;
 void solve(Node* root) {
     if(!root) return ; 
     solve(root->left);
     if(prev){
         result = min(result, abs(prev->data -  root->data));
         
     }
     prev = root; 
     solve(root->right);
 }
    int absDiff(Node *root) {
        result = 1e9;
        solve(root);
        return result; 
        
    }
};