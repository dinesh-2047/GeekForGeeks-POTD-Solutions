// Distribute Candies


/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
 int dfs(Node *root, int &result){
     if(!root) return 0 ; 
     int l = dfs(root->left, result);
     int r = dfs(root->right, result);
     
     result += abs(l) + abs(r);
     return root->data - 1 + l + r;
 }
    int distCandy(Node* root) {
       int result = 0 ; 
       dfs(root, result);
       return result;
        
    }
};