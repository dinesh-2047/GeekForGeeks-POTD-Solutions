// Count Subsequences Divisible by n

class Solution {
  public:
  int N ; 
  int mod = 1e9 + 7; 
  vector<vector<int>> dp; 
  int solve(string &s, int &n, int i , int rem){
      if(i >= N){
          if( rem == 0 ){
              return 1; 
          }
          return 0 ; 
      }
      if(dp[i][rem]!=-1) return dp[i][rem];
      int not_take = solve(s, n ,  i + 1, rem )%mod;
      int new_sum = rem * 10 + (s[i] - '0');
      int take = solve(s, n , i  + 1, new_sum%n )%mod;
      
      return dp[i][rem] =  (take+ not_take)%mod; 
  }
    int countSubsequences(string& s, int n) {
        N = s.length();
        dp.assign(N, vector<int> (n, -1));
        return solve(s, n, 0, 0)-1;
        
    }
};