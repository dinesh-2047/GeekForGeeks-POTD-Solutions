// Longest Palindrome in a String

// Approach tabulation 

class Solution {
    public:
      string longestPalindrome(string &s) {
  int n = s.size();
  
          int ans = 1;
  
          vector<vector<bool>> dp(n+1,vector<bool>(n+1,false));
  
          string ansstring = s.substr(0,1);
  
          for(int i = 0;i<n;i++)
  
          {
  
              dp[i][i] = true;
  
              
  
              
  
          }
  
          for(int i = n-1;i>=1;i--)
  
          {
  
              if(s[i] == s[i-1])
  
              {
  
                  dp[i-1][i] = true;
  
                  ans = 2;
  
                  ansstring = s.substr(i-1,2);
  
                  
  
              }
  
          }
  
          for(int len = 3;len<=n;len++)
  
          {
  
              for(int i = 0;i<=n-len;i++)
  
              {
  
                  int j = i+len - 1;
  
                  
  
                  if((s[i] == s[j])&& dp[i+1][j-1])
  
                  {
  
                      dp[i][j] = true;
  
                      if(len>ans)
  
                      { 
  
                          ans = len;
  
                          ansstring = s.substr(i,j-i+1);
  
                      }
  
                      
  
                  }
  
              }
  
          }
  
          
  
        
  
          return ansstring;
  
      }
  
  };
          
   