// Longest Common Subsequence


class Solution {
    public:
    int n ; 
    int m ; 
    int solve(string &s1, string &s2, int i , int j, vector<vector<int>> &dp ){
        if(i==n || j == m) return 0 ; 
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]) return dp[i][j] =  1 + solve(s1, s2, i + 1 ,j+1,dp);
        
        return dp[i][j] =  max(solve(s1, s2, i+1 ,j,dp ) , solve(s1, s2 , i ,j+1,dp));
        
    }
      int lcs(string &s1, string &s2) {
            n = s1.length();
             m = s2.length();
          vector<vector<int>>dp(n+1, vector<int>(m+1 ,-1));
          return solve(s1, s2, 0 , 0,dp );
          
      }
  };