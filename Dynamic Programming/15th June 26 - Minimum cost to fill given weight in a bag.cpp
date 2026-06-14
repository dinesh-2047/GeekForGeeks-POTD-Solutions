// Minimum cost to fill given weight in a bag


class Solution {
  public:
  int n ; 
  vector<vector<int>> dp; 
  int solve(vector<int> &cost, int i , int w){
      if(w == 0 ) return 0; 
      if(i >= n ){
          if(w == 0 ) return 0; 
          return 1e9; 
      }
      
      if(dp[i][w]!=-1) return dp[i][w];
      
      int not_take = solve(cost, i + 1, w);
      int take = 1e9; 
      if(w-(i+1) >= 0 && cost[i]!=-1){
          take = cost[i] +  min(solve(cost, i + 1, w - (i + 1)), solve(cost , i , w-(i+1)));
      }
      return dp[i][w]=  min(take, not_take);
  }
    int minimumCost(vector<int> &cost, int w) {
        n = cost.size();
        dp.assign(n, vector<int> (w + 1, -1));
        int result =  solve(cost, 0, w) ;
        return (result == 1e9 || result < 0 ) ? -1 : result; 
        
    }
};
