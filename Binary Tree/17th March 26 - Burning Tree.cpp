// Burning Tree

/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int minTime(Node* root, int target) {
        unordered_map<Node*, Node* >parent ; 
        
        queue<Node*>q; 
        
        q.push(root);
        
        Node* targetNode = nullptr; 
        
        while(!q.empty()){
            int n  = q.size();
            
            while(n--){
                auto curr = q.front();
                q.pop();
                
                if(curr->data == target){
                    targetNode = curr; 
                }
                
                if(curr->left){
                    q.push(curr->left);
                    parent[curr->left] = curr; 
                }
                if(curr->right){
                    q.push(curr->right);
                    parent[curr->right] = curr; 
                }
            }
        }
        
        int result = 0 ; 
        
        unordered_map<Node* , bool>visited; 
        queue<Node*>burn ;
        burn.push(targetNode);
        visited[targetNode] = true; 
        
        while(!burn.empty()){
            int n = burn.size();
            bool flag = false; 
            while(n--){
                auto curr = burn.front();
                burn.pop();
                
                if(curr->left && !visited[curr->left]){
                    visited[curr->left] = true; 
                    burn.push(curr->left);
                    flag = true; 
                }
                
                if(curr->right && !visited[curr->right]){
                    visited[curr->right] = true; 
                    burn.push(curr->right);
                    flag = true; 
                }
                
                if(parent[curr] && !visited[parent[curr]]){
                    visited[parent[curr]] = true; 
                    burn.push(parent[curr]);
                    flag = true; 
                }
                
            }
            if(flag) result++;
        }
        return result; 
        
    }
};