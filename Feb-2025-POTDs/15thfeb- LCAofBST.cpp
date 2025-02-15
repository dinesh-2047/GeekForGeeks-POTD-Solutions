
// LCA OF BST 
/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/
// Approach 1
class Solution {
    public:
      Node* LCA(Node* root, Node* n1, Node* n2) {
          if(root == nullptr) return  NULL ;
          
          
          if(root == n1 || root == n2) return root; 
          
          Node* leftN = LCA(root->left, n1, n2);
          Node* rightN = LCA(root->right, n1 , n2);
          
          if(leftN!=nullptr && rightN!=nullptr) return root; 
          
          if(leftN!=nullptr && rightN == nullptr) return leftN; 
          if(rightN!=nullptr && leftN == nullptr ) return rightN; 
          return nullptr;
      }
  };


//   Approach 2

class Solution {
    public:
      Node* LCA(Node* root, Node* n1, Node* n2) {
          if(root == nullptr) return  NULL ;
          
          
          int curr = root->data;
          
          if(curr < n1->data && curr < n2->data) {
              return LCA(root->right, n1 , n2);
              
              
          }
          
          if(curr > n1->data && curr > n2->data){
              return LCA(root->left, n1, n2 );
          }
          return root; 
      }
  };
  