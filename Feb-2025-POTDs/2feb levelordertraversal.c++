// Binary Tree Level order traversal

class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>>ans;
        
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            int N = q.size();
            vector<int>temp;
            
            while(N--){
                auto current = q.front();
                q.pop();
                temp.push_back(current->data);
                
                if(current->left)q.push(current->left);
                if(current->right) q.push(current->right);
            }
           ans.push_back(temp);
        }
        return ans;
    }
};