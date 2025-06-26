// Mobile numeric keypad


class Solution {
  public:
  int dfs(int i , int n , vector<vector<int>> &adj, vector<vector<int>> &dp){
      if(n==1) return 1; 
      
      if(dp[i][n]!=-1) return dp[i][n];
      
      int ans = 0 ; 
      for(auto &nbr : adj[i]){
          ans += dfs(nbr, n-1, adj,dp);
      }
      
      return dp[i][n] = ans; 
  }
  
    int getCount(int n) {
        
        if(n==1) return 10 ; 
        
        vector<vector<int>>adj ={ {0,8} , {1,2 , 4} , { 2,1,3,5} , { 3,2,6},{4,1,5,7} ,{5,2,4,6,8},{6,5,3,9},{7,4,8},{8,5,7,0,9},{9,8,6}};
        
         int result = 0 ;
         vector<vector<int>> dp(11, vector<int>(n+1, -1));
         for(int i = 0 ;  i <=9;i++){
             result += dfs(i, n , adj,dp);
         }
         return result; 
    }
};