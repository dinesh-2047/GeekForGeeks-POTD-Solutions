// Count Palindromic Strings with Constraints

class Solution {
  public:
  int mod = 1e9 + 7 ; 
  
  int dp[27][53];
  long long solve(int k, int m){
      if(m == 0 ) return 1; 
      if(m > k ) return 0 ; 
      
      if(dp[k][m]!=-1) return dp[k][m];
      
      return dp[k][m]= (solve(k, m-1)%mod * (k-m+1))%mod; 
  }
    int palindromicStrings(int n, int k) {
        memset(dp, -1, sizeof(dp));
        long long result = 0 ;
        
        for(int len = 1; len <= n ; len++){
            int half = len/2; 
            
            if(half > k ) continue; 
            
            long long ways = solve(k, half)%mod; 
            
            if(len%2 == 0 ) result = (result + ways)%mod; 
            else {
                ways = (ways * (k - half))%mod; 
                result = (result + ways)%mod; 
            }
        }
        return result%mod; 
        
    }
};