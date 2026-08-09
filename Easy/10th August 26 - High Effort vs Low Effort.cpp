// High Effort vs Low Effort
class Solution {
  public:
  int n;
  vector<vector<int>> dp; 
  int solve(vector<int> &h, vector<int> &l ,int i, int prev){
      if(i >= n ) return 0 ; 
      if(dp[i][prev]!=-1) return dp[i][prev];
      int no_task = solve(h, l , i + 1, 0);
      int low_task = l[i] + solve(h, l, i + 1, 1);
      int high_task = 0 ; 
      if(!prev){
          high_task = h[i] + solve(h, l , i + 1, 1);
      }
      return dp[i][prev]=  max({no_task, low_task, high_task});
      
  }
    int maxTask(vector<int>& h, vector<int>& l) {
          
        n = h.size();
        dp.resize(n + 1, vector<int>(2 , -1));
        return solve(h, l , 0,0);
    }
};