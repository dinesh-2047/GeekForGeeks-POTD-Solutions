// Top View of Binary Tree

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        
        queue<pair<Node*, int >>q; 
        q.push({root, 0});
        
        vector<int>result; 
        map<int , int>mp; 
        
        while(!q.empty()){
            int n = q.size();
            while(n--){
                auto curr = q.front();
                q.pop();
                
                if(!mp.count(curr.second))
                mp[curr.second] = curr.first->data; 
                if(curr.first->left){
                    q.push({curr.first->left, curr.second - 1});
                }
                if(curr.first->right){
                    q.push({curr.first->right, curr.second + 1});
                }
                
            }
        }
        
        for(auto &pair : mp){
            result.push_back(pair.second);
        }
        return result; 
        
    }
};