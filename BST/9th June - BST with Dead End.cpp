// BST with Dead End


class Solution {
  public:
  bool solve(Node* root , unordered_set<int> &st){
      if(root == nullptr) return false; 
      
      if(root->left == nullptr && root->right == nullptr){
          if(st.count(root->data-1) && st.count(root->data + 1) ) return true; 
      }
      st.insert(root->data);
      return solve(root->left,st) || solve(root->right,st);
  }
  
    bool isDeadEnd(Node *root) {
        unordered_set<int>st; 
        st.insert(0);
       return  solve(root, st);
        
    }
};