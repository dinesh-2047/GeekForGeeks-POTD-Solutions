// Longest Palindromic Subsequence

// Approach 1 recursion 
class Solution {
    public:
    int solve(int i, int j, string s, string rev)
  {
      if (i<0 || j <0) return 0;
      if (s[i] == rev[j])
          return 1 + solve(i - 1, j - 1, s, rev);
      else
          return max (solve(i, j - 1, s, rev), solve(i - 1, j, s, rev));
  }
      int longestPalinSubseq(string &s) {
           int n = s.length();
      string rev = s;
      reverse(rev.begin(), rev.end());
      return solve(n - 1, n - 1, s, rev);
      }
  };


// Rec + memo 
class Solution {
    public:
    int solve(int i, int j, string s, string rev, vector<vector<int>> &dp)
  {
      if (i<0 || j <0) return 0;
      if(dp[i][j] != -1) return dp[i][j];
      if (s[i] == rev[j])
          return dp[i][j] =  1 + solve(i - 1, j - 1, s, rev,dp);
      else
          return dp[i][j] =  max (solve(i, j - 1, s, rev,dp), solve(i - 1, j, s, rev,dp));
  }
      int longestPalinSubseq(string &s) {
           int n = s.length();
      string rev = s;
      reverse(rev.begin(), rev.end());
      vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
      return solve(n - 1, n - 1, s, rev,dp);
      }
  };



// tabulation 

class Solution {
    public:
      int longestPalinSubseq(string &s) {
           string rev = s;
      reverse(rev.begin(), rev.end());
      int n = s.size();
      vector<vector<int>> dp(n+1,vector<int>(n+1,0));
      for(int i=0;i<=n;i++){
          dp[i][0] = 0;
          dp[0][i] = 0;
      }
      for(int i=1;i<=n;i++){
          for(int j=1;j<=n;j++){
              if(s[i-1]==rev[j-1])
                  dp[i][j] = 1 + dp[i-1][j-1];
              else
                  dp[i][j] = 0 + max(dp[i-1][j],dp[i][j-1]);
          }
      }
      return dp[n][n];
  
      }
  };

// space optimization 

class Solution {
    public:
      int longestPalinSubseq(string &s) {
           string rev = s;
          reverse(rev.begin(), rev.end());
          int n = s.size();
          vector<int> prev(n+1, 0), curr(n+1, 0);
          for(int i = 1; i <= n; i++)
          {
              for(int j = 1; j <= n; j++)
              {
                  if(s[i-1] == rev[j-1]) curr[j] = 1 + prev[j-1];
                  else curr[j] = max(curr[j-1],prev[j]);
              }
              prev = curr;
          }
          return prev[n];
  
      }
  };