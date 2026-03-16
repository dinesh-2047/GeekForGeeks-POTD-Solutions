// K Sum Paths


class Solution {
  public:
unordered_map<int , int>mp; 
  int solve(Node* root, int k , int currSum ){
      if(!root) return 0 ;
      
      currSum  += root->data; 
      
      int count = 0 ; 
      
      int r = currSum - k ; 
      if(mp.count(r)){ 
          count += mp[r];
      }
      mp[currSum]++;
      
      count += solve(root->left, k , currSum);
      count += solve(root->right , k , currSum);
      
      mp[currSum]--;
      return count; 
      
      
  }
    int countAllPaths(Node *root, int k) {
        mp[0] = 1; 
    return    solve(root, k, 0 );
     
        
    }
};