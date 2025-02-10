// Check for BST  (if given tree is bst or not)


// Approach 1 
class Solution {
    public:
      // Function to check whether a Binary Tree is BST or not.
      void inorder(Node* root, vector<int>&in){
          if(root == nullptr) return ; 
          
          inorder(root->left, in);
          in.push_back(root->data);
          inorder(root->right, in );
      }
      bool isBST(Node* root) {
          vector<int>in;
          inorder(root, in);
          
          for(int i = 0 ; i<in.size()-1; i++){
              if(in[i] > in[i+1]) return false;
          }
          return true;
      }
  };



//   Approach 2 
class Solution {
    public:
      // Function to check whether a Binary Tree is BST or not.
  bool bstUtil(Node* root, int min , int max){
      if(root == nullptr) return true; 
      
      
      if(root->data<=min || root->data>=max) return false; 
      
      return bstUtil(root->left, min , root->data) && bstUtil(root->right, root->data, max);
  }    
      bool isBST(Node* root) {
         return bstUtil(root, INT_MIN, INT_MAX);
          
      }
  };



//   Approach 3 

class Solution {
    public:
  void inorder(Node* root, int& prev, bool& check){
      if(root==nullptr || check == false) return ; 
      
      inorder(root->left, prev, check);
      
      if(prev>=root->data){
          check = false; 
          return ;
      }
      prev = root->data;
      inorder(root->right, prev , check );
  }
      bool isBST(Node* root) {
          int prev = INT_MIN;
          bool check = true; 
          inorder(root, prev , check);
          return check ;
      }
  };