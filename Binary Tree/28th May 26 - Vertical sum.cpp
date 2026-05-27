// Vertical sum

/* Structure of binary tree node
class Node{
public:
    int data;
    Node* left, right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
}
*/
class Solution {
  public:
  void solve(Node*root,map<int,int>&m){
      queue<pair<Node*,int>>q;
      q.push({root,0});
      
        while(!q.empty()){
            Node*curr = q.front().first;
            int hd = q.front().second;
            q.pop();
          
            m[hd] += curr->data;
            if(curr->left){
              q.push({curr->left,hd-1});
            }
            if(curr->right){
              q.push({curr->right,hd+1});
            }
        }
    }
    vector<int> verticalSum(Node *root) {
        map<int,int>m;
        solve(root,m);
        vector<int>arr;
        
        for(auto &i : m){
            arr.push_back(i.second);
        }
        return arr;
    }
};