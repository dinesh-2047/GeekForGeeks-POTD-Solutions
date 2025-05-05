// Left View of Binary Tree



// Using recursion 
class Solution {
    public:
  void solve(Node* root, int level , vector<int> &ans){
      if(root == nullptr) return ;
      
      if(level== ans.size()){
          ans.push_back(root->data);
      }
      
      solve(root->left, level + 1, ans);
      solve(root->right , level+ 1, ans);
  }
    
      vector<int> leftView(Node *root) {
         vector<int>ans; 
          solve(root , 0 , ans);
          return ans; 
          
      }
  };




// Using queue 
class Solution {
    public:
      vector<int> leftView(Node *root) {
          if(root == nullptr) return {};
          
          vector<int> ans;
          queue<Node*> q;
          q.push(root);
          
          while(!q.empty()){
              int n = q.size();
              Node* node = nullptr;
              
              // Process all nodes at the current level
              while(n--) {
                  node = q.front();
                  q.pop();
                  
                  // Add children to the queue in reverse order (right first, left second)
                  if(node->right) q.push(node->right);
                  if(node->left) q.push(node->left);
              }
              
              // After the inner loop, the 'node' will hold the leftmost node of this level
              ans.push_back(node->data);
          }
          
          return ans;
      }
  };
  