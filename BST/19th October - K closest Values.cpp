// K closest Values


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
  priority_queue<pair<int , int>, vector<pair<int , int>>, greater<>>pq; 
  void solve(Node* root , int target){
      if(!root) return; 
      
      solve(root->left, target);
      pq.push({abs(target - root->data), root->data});
      solve(root->right, target);
  }
  
    vector<int> getKClosest(Node* root, int target, int k) {
         solve( root, target );
         vector<int>result; 
         
         while(k--){
             result.push_back(pq.top().second);
             pq.pop();
         }
         return result; 
        
    }
};