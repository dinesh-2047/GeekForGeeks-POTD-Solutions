// Root to Leaf Paths

class Solution {
    public:
    void solve(Node* root , vector<vector<int>> &result, vector<int> &temp){
        if(root == nullptr ){
            
            return; 
        }
          temp.push_back(root->data);
        if(root -> left == nullptr && root -> right  == nullptr) {
          result.push_back(temp);
      
        }
      
        solve(root->left, result , temp);
       
        solve(root->right , result , temp);
         temp.pop_back();
    }
    
    
      vector<vector<int>> Paths(Node* root) {
         if(root == nullptr) return {{}};
         
         vector<vector<int>>result; 
         vector<int>temp ; 
         
         solve(root , result, temp );
         
         return result; 
          
      }
  };
  