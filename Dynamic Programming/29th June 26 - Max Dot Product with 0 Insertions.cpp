// Max Dot Product with 0 Insertions

class Solution {
  public:
  int n, m; 
  vector<vector<int>> dp; 
  int solve(vector<int> &a, vector<int> &b, int i , int j){
      if( j >= m || (n - i ) < (m - j) ) return 0 ;
      if(dp[i][j] != -1) return dp[i][j];
       return dp[i][j] =  max(a[i] * b[j] + solve(a, b, i + 1, j + 1), solve(a, b, i + 1,  j ));
  }
 
  
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        n = a.size();
        m = b.size();
        dp.resize(n + 1, vector<int> (m + 1, -1));
        return solve(a, b, 0 , 0);
    }
};
