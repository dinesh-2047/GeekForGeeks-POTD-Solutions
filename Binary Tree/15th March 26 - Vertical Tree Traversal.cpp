// Vertical Tree Traversal

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
      map<int , map<int , vector<int>>> mp ;
      vector<vector<int>>result; 
      
      queue<tuple<Node*, int, int>>q; 
      q.push({root, 0 , 0});
      
      while(!q.empty()){
          int n = q.size();
          while(n--){
              auto [curr, vd, level] = q.front();
              q.pop();
              
              mp[vd][level].push_back(curr->data);
              if(curr->left){
                  q.push({curr->left, vd-1, level + 1});
              }
              if(curr->right){
                  q.push({curr->right , vd + 1, level + 1});
              }
          }
      }
      
      for(auto &[_, mpp] : mp){
               vector<int>vec; 
          for(auto &[_, ms] : mpp){
         
             for(auto &s : ms){
                 vec.push_back(s);
             }
              
          }
          result.push_back(vec);
         
      }
      return result; 
      
        
    }
};