// Longest Consecutive Path in Binary tree

/* Structure of Binary Tree Node
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

int result = 0 ; 
void solve(Node* root, Node* parent , int len ){
    if(!root) return ;
    
    
    if(parent && root->data == parent->data + 1) len++;
    else len = 1; 
    
    result = max(result, len);
    
    
    solve(root->left, root, len);
    solve(root->right, root,  len);
}
    int longestConsecutive(Node* root) {
      if(!root ) return -1; 
      
      
      solve(root, nullptr, 0);
      
      return result == 1 ? -1 : result;
      
        
    }
};