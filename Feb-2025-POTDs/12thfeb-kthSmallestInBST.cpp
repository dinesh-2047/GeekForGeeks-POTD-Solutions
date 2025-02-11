// Kth smallest in bst  


// Approach 1 
class Solution {
    public:
   void inorder(Node* root, vector<int>&v){
       if(root == nullptr) return ; 
       
       inorder(root->left, v);
       v.push_back(root->data);
       inorder(root->right, v);
   }
      int kthSmallest(Node *root, int k) {
          
          vector<int>v;
          inorder(root, v);
          
          if(v.size() <k) return -1;
          
          return v[k-1];
          
      }
  };



// Approach 2; 

class Solution {
    public:
    int count = 0 ; 
    int ans ;
    
      int kthSmallest(Node *root, int k) {
          
          if(root == nullptr) return 0;
          
         kthSmallest(root->left, k);
          count++;
          if(count==k) ans= root->data;
         kthSmallest(root->right,k);
          
         if(k>count) return -1 ; 
         else return ans; 
        
          
      }
  };
