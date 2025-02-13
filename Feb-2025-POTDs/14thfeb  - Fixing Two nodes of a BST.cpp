// Fixing Two nodes of a BST


class Solution {
    public:
   void solve(Node* &root, Node* &prev, Node* &a, Node* &b) {
       if(root == nullptr) return; 
       
       solve(root->left, prev, a , b );
       if(prev!=nullptr and root->data < prev->data){
           if(a==nullptr) {
               a = prev ;
           }
               b =root;
           
       }
       prev = root;
       solve(root->right, prev, a , b );
   }
    
      void correctBST(Node* root) {
         Node*prev = nullptr;
         Node* a = nullptr;
         Node* b = nullptr;
         
         solve(root, prev, a , b );
         
         swap(a->data, b->data);
       
      }
  };