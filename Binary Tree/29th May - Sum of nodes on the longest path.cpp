// Sum of nodes on the longest path


class Solution {
  public:
  void solve(Node *root, int sum , int count , int &maxCount , int &result ){
      if(root == nullptr){
          if(count > maxCount){
              result = sum;
              maxCount = count; 
          }
          else if(count == maxCount) result = max(result ,sum);
          return; 
      }
      
      count++;
      sum+=root->data;
      
      solve(root->left, sum ,  count , maxCount , result);
      solve(root->right ,sum ,  count , maxCount , result);
      
  }
  
  
    int sumOfLongRootToLeafPath(Node *root) {
        int sum = 0 ; 
        int count = 0 ; 
        int maxCount = 0 ; 
        int result = 0 ; 
        
        
         solve(root , sum , count, maxCount , result);
         
         return result; 
        
    }
};