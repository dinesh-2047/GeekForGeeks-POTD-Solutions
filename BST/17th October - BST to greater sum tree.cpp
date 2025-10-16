// BST to greater sum tree

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
  public:
  int sum = 0 ; 
  void reverseInorder(Node *root){
      if(!root) return ; 
      reverseInorder(root->right);
      int rootVal = root->data; 
      root->data =  sum ; 
      sum += rootVal; 
      
      reverseInorder(root->left);
  }
    void transformTree(Node *root) {
         reverseInorder(root);
        
    }
};