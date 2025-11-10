// Shortest Common Supersequence





class Solution {
public:
    int solve(string &str1, string &str2, int i, int j, vector<vector<int>>&dp) {
        if (i == str1.length()) return dp[i][j]=  str2.length() - j;
        if (j == str2.length()) return dp[i][j]=  str1.length() - i;
        
        if(dp[i][j]!=-1) return dp[i][j]; 

        if (str1[i] == str2[j]) {
            return dp[i][j] = 1 + solve(str1, str2, i + 1, j + 1,dp);
        } else {
            return dp[i][j] =  1 + min(solve(str1, str2, i + 1, j,dp), solve(str1, str2, i, j + 1,dp));
        }
    }

    int shortestCommonSupersequence(string &s1, string &s2) {
        int n = s1.length();
        int m = s2.length();
        
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return solve(s1, s2, 0, 0,dp);
    }
};
