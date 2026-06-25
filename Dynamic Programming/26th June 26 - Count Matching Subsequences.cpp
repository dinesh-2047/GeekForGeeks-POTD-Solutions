// Count Matching Subsequences

class Solution {
  public:
  int mod = 1e9 + 7; 
  int n , m ; 
  vector<vector<int>> dp; 
  int solve(string &s1, string &s2, int i ,int j){
      if(j >= m ) return 1 ; 
     if(i >= n){
         return 0; 
     }
     
     if(dp[i][j]!=-1) return dp[i][j];
     int not_take = solve(s1, s2, i + 1, j);
     int take = 0;
     if(s1[i] == s2[j]){
         take = solve(s1, s2, i + 1, j + 1);
     }
    
     return dp[i][j] =  ( take + not_take)%mod; 
  }
    int countWays(string &s1, string &s2) {
        n = s1.length();
        m = s2.length();
        if(n <m) return 0; 
        dp.assign(n + 1 , vector<int>(m + 1, -1));
       return solve(s1, s2,0, 0);
       
        
    }
};
