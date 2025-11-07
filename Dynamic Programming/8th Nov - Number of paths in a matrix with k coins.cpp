// Number of paths in a matrix with k coins


class Solution {
  public:
  int n , m ;
   int solve(int i, int j, int k, vector<vector<int>>& arr, vector<vector<vector<int>>>& dp){
        if(i==0 && j==0){
            if(k==arr[i][j]) return 1;
            else return 0;
        }
        if(i<0 || j<0) return 0;
        
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        
        int up = 0; int left = 0;
        if(arr[i][j]<=k) up += solve(i-1, j, k-arr[i][j], arr, dp);
        if(arr[i][j]<=k) left += solve(i, j-1, k-arr[i][j], arr, dp);
        return dp[i][j][k] = up+left;
    }
    
    long long numberOfPath( vector<vector<int>> &mat , int k ){
         m = mat.size();
         n = mat[0].size();
     
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(k+1,-1)));
        return solve(m-1, n-1, k, mat, dp);
    }
};