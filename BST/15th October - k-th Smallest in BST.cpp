// k-th Smallest in BST


// Approach 1
class Solution {
  public:
  void inorder(Node* root , vector<int> &vec){
       if(!root){
           return; 
       }
       
       inorder(root->left, vec);
       vec.push_back(root->data);
       inorder(root->right, vec);
  }
    int kthSmallest(Node *root, int k) {
        vector<int>vec; 
        inorder(root , vec);
        
        if(k > vec.size() ) return -1; 
        
        return vec[k-1];
        
        
    }
};






//approach 2 
class Solution {
  public:
  int count = 0 ; 
  int result; 
    int kthSmallest(Node *root, int k) {
        if(!root) return 0 ; 
        
        kthSmallest(root->left , k);
        count++;
        if(count == k ) result = root->data;  
        kthSmallest(root->right , k);
        
        if(k > count) return -1; 
        
        return result; 
        
        
    }
};