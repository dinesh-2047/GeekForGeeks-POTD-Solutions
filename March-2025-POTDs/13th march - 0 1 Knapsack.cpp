// 0 1 Knapsack

// Approach 1 Rec + memo 
class Solution {
    public:
    int solve(int w , vector<int> &val , vector<int> &wt, int i, vector<vector<int>> &dp ){
        if(i==val.size() || w==0) return 0 ;
        
        if(dp[w][i]!=-1) return dp[w][i];
        
        int take = 0;
        if(wt[i]<=w){
            take = val[i] + solve(w-wt[i], val , wt , i+1,dp );
        }
        
        int not_take = solve(w, val , wt , i+1,dp);
        
        return dp[w][i] =  max(take, not_take);
        
    }
      int knapsack(int W, vector<int> &val, vector<int> &wt) {
          int n = val.size();
          vector<vector<int>>dp(W+1, vector<int>(n+1, -1));
         return solve(W, val , wt, 0,dp);
          
      }
  };


//   Approach 2 Tabulation /
class Solution {
    public:
   
        
    
      int knapsack(int W, vector<int> &val, vector<int> &wt) {
          int n = val.size();
          vector<vector<int>>dp(W+1, vector<int>(n+1, 0));
        
        for(int i =  n- 1; i>=0; i--){
            for(int j = 0 ; j<=W; j++){
                if(wt[i] <= j) {
                    dp[j][i] = max( val[i] +dp[j-wt[i]][i+1], dp[j][i+1]);
                }
                else{
                    dp[j][i] = dp[j][i+1];
                }
            }
        }
        return dp[W][0];
          
      }
  };