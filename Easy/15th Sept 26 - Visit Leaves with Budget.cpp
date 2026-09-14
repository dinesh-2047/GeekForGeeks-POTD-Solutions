// Visit Leaves with Budget

/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    int getCount(Node *root, int k) {
        vector<int> vec; 
        
        queue<Node*> q; 
        q.push(root);
        int level = 1; 
        while(!q.empty()){
            int n = q.size();
            while(n--){
                auto curr = q.front();
                q.pop();
                
                if(!curr->left && !curr->right){
                    vec.push_back(level);
                }
                
                if(curr->left){
                    q.push(curr->left);
                }
                
                if(curr->right) q.push(curr->right);
            }
            level++;
        }
        
        sort(begin(vec), end(vec));
        
        int result = 0; 
        
        int cost = 0; 
        
        for(int i = 0; i  < vec.size(); i++){
            if(cost + vec[i] <= k) {
                cost += vec[i];
                result++;
            }
        }
        return result;
        
        
        
    }
};