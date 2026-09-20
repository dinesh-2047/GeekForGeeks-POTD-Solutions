// Check Level Anagrams in Binary Trees

/* Structure of binary tree Node
class Node {
    public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool areAnagrams(Node* root1, Node* root2) {
      queue<Node*> q1; 
      q1.push(root1);
     
      queue<Node*> q2;
      q2.push(root2);
      
      while(!q1.empty() || !q2.empty()){
          int n1 = q1.size();
          unordered_map<int , int> mp1, mp2; 
          while(n1--){
              auto curr = q1.front();
              q1.pop();
              
              mp1[curr->data]++;
              if(curr->left) q1.push(curr->left);
              if(curr->right) q1.push(curr->right);
          }
          
          int n2 = q2.size();
          while(n2--){
                auto curr = q2.front();
              q2.pop();
              
              mp2[curr->data]++;
              if(curr->left) q2.push(curr->left);
              if(curr->right) q2.push(curr->right);
          }
          
          if(mp1 != mp2) return false; 
      }
      return true; 
        
    }
};

