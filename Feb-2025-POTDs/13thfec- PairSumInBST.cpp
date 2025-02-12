// Pair sum in bst 

// Approach using inorder and binary search 

class Solution {
    public:
    void inorder(Node* root, vector<int>&v){
        if(root == nullptr) return ; 
        
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
      bool findTarget(Node *root, int target) {
          vector<int>v;
          
          inorder(root, v);
          int n = v.size();
          int i = 0 ; 
          int j = n-1; 
          
          while(i<j){
              int sum = v[i] + v[j];
              
              if(sum == target) return true; 
              
              else if(sum > target) {
                  j--;
              }
              else i++;
          }
          
          return false; 
      }
  };