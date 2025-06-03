// LCS of three strings

// Rec + memo 
class Solution {
  public:
    int lcs(int i, int j, int k, string& s1, string& s2, string& s3, vector<vector<vector<int>>>& dp){
        if(i<0 || j<0 || k<0)
            return 0;
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        
        if(s1[i]==s2[j] && s1[i]==s3[k])
            return dp[i][j][k] = 1 + lcs(i-1, j-1, k-1, s1, s2, s3, dp);
        return dp[i][j][k] = max({lcs(i-1, j, k, s1, s2, s3, dp), lcs(i, j-1, k, s1, s2, s3, dp), lcs(i, j, k-1, s1, s2, s3, dp)});
            
    }
  
    int lcsOf3(string& s1, string& s2, string& s3) {
        // Code here
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        
        vector<vector<vector<int>>> dp(n1, vector<vector<int>> (n2, vector<int> (n3, -1)));
        
        return lcs(n1-1, n2-1, n3-1, s1, s2, s3, dp);
    }
};



//Tabulation ]
class Solution {
  public:
    int lcsOf3(string& s1, string& s2, string& s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();
        
        // 3D DP table
        int dp[n1 + 1][n2 + 1][n3 + 1];
        
        // Initialize all dp cells to 0
        for (int i = 0; i <= n1; i++) {
            for (int j = 0; j <= n2; j++) {
                for (int k = 0; k <= n3; k++) {
                    // Base Case
                    if (i == 0 || j == 0 || k == 0) {
                        dp[i][j][k] = 0;
                    }
                    // If current characters in all 3 strings match
                    else if (s1[i - 1] == s2[j - 1] && s1[i - 1] == s3[k - 1]) {
                        dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                    }
                    // Else take max from reducing one of the strings
                    else {
                        dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
                    }
                }
            }
        }
        
        return dp[n1][n2][n3];
    }
};