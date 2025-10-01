// Unique K-Number Sum


class Solution {
  public:

  
  void solve(int n , int k ,int start,  vector<int>curr, vector<vector<int>> &result, int sum ){
      if(curr.size() == k ){
    
         if(sum == n ){
             result.push_back(curr);
         }
    
          return ; 
      }
      
      for(int i = start; i <= 9 ; i++){
          curr.push_back(i);
          solve(n , k , i + 1, curr, result, sum + i );
          curr.pop_back();
        
      }
      
  }
  
    vector<vector<int>> combinationSum(int n, int k) {

        vector<vector<int>>result; 
        vector<int>curr; 
        int sum  = 0 ; 
        
        solve(n , k ,1 , curr, result, sum );
        
        return result; 
    }
};