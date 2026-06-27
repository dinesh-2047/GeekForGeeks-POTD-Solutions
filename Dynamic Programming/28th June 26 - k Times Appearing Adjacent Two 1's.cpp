// k Times Appearing Adjacent Two 1's

class Solution {
  public:
  int dp[1001][1001][2];
  int mod = 1e9 + 7 ; 
  int solve(int n , int k, int i , int count, int prev){
      if(i == n){
          return count == k;
      }
      
      if(dp[i][count][prev]!=-1) return dp[i][count][prev];
      
      int zero = solve(n , k , i + 1, count, 0);
     
     int  one =  solve(n , k , i + 1, count + (prev == 1), 1);
      
      return dp[i][count][prev] =  (zero + one)%mod ;
  }
    int countStrings(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(n , k, 0, 0, 0);
        
    }
};