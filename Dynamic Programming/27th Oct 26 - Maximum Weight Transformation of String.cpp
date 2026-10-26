// Maximum Weight Transformation of String

class Solution {
  public:
  int n ;
  vector<int>dp; 
  int solve(string &s, int i){
      if(i >= n){
          return 0 ; 
      }
      
      if(dp[i]!=-1) return dp[i];
      
      int single = 1 + solve(s, i + 1);
      int pair = 0 ; 
      if(i + 1 < n ){
          int cost = (s[i] == s[i + 1]) ? 1 : 0;
          pair = 4 - cost + solve(s, i + 2);
      }
      return dp[i] =  max(single, pair);
  }
    int getMaxWeight(string &s) {
        n = s.length();
        dp.assign(n + 1, -1);
        return solve(s, 0);
        
    }
};
