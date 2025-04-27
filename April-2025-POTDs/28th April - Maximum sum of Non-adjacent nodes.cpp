// Maximum sum of Non-adjacent nodes


class Solution {
    public:
      
      pair<int ,int>solve(Node* root){
          if(root == nullptr) {
               return {0,0};
          }
          
          pair<int,int>left = solve(root ->left);
          pair<int, int>right = solve(root->right);
          
          pair<int , int>result ; 
          
          result.first = root->data + left.second + right.second; 
          
          result.second = max(left.first, left.second)  + max(right.first, right.second);
          return result; 
      }
      
      int getMaxSum(Node *root) {
          pair<int , int>result = solve(root);
          return max(result.first, result.second);
          
      }
  };
  