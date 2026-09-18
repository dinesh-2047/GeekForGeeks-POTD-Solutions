// Min Cost To Make Two Strings Identical


class Solution {
  public:
  int n , m ; 
  int dp[1001][1001];
  int solve(string &s1, string &s2, int &costS1, int &costS2, int i , int j){
      if(i >= n && j >= m ){
          return 0 ; 
      } 
      
      if (i >= n) return (m - j) * costS2;

            
      if (j >= m)  return (n - i) * costS1;
      
      if(dp[i][j]!=-1) return dp[i][j];
      
      int result = 1e9 ;
      if(s1[i] == s2[j]){
          result = min(result, solve(s1, s2, costS1, costS2, i + 1, j + 1));
      }
      else {
          result = min(result, costS1 + solve(s1, s2, costS1, costS2, i + 1, j));
          result = min(result, costS2 + solve(s1, s2, costS1, costS2, i , j + 1));
          result = min(result, costS1 + costS2 + solve(s1, s2, costS1, costS2, i + 1, j + 1));
      }
      return dp[i][j] =  result; 
  }
    int findMinCost(string &s1, string &s2, int costS1, int costS2) {
        n = s1.length();
        m = s2.length();
         memset(dp, -1, sizeof(dp));
        return solve(s1, s2, costS1, costS2, 0, 0);
        
    }
};