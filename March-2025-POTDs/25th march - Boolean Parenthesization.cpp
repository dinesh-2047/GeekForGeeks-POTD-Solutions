// Boolean Parenthesization


// Approach1 : rec + memo 

2;
class Solution {
    public:
        int solve(string &s, int i, int j, bool isTrue, vector<vector<vector<int>>>&dp) {
            // Base case: If there is only one character
            if (i > j) return 0;
            if (i == j) {
                if (isTrue) return s[i] == 'T';
                else return s[i] == 'F';
            }
            
            if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
    
            int ways = 0;
            // Iterate over the operators (k is always an operator position)
            for (int k = i + 1; k < j; k += 2) {
                // Compute left and right subproblems
                int lt = solve(s, i, k - 1, true,dp);
                int lf = solve(s, i, k - 1, false,dp);
                int rt = solve(s, k + 1, j, true,dp);
                int rf = solve(s, k + 1, j, false,dp);
    
                // Apply the operator
                if (s[k] == '&') {
                    if (isTrue) ways += (lt * rt);
                    else ways += (lt * rf) + (lf * rt) + (lf * rf);
                } 
                else if (s[k] == '|') {
                    if (isTrue) ways += (lt * rt) + (lt * rf) + (lf * rt);
                    else ways += (lf * rf);
                } 
                else if (s[k] == '^') {
                    if (isTrue) ways += (lt * rf) + (lf * rt);
                    else ways += (lt * rt) + (lf * rf);
                }
            }
    
            return dp[i][j][isTrue] =  ways;
        }
    
        int countWays(string &s) {
            int n = s.length();
            vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(n+1, vector<int>(2,-1)));
            return solve(s, 0, n - 1, true,dp);
        }
    };

    

    // Approach 2 - Tabulation 
    class Solution {
        public:
            int countWays(string &s) {
                int n = s.length();
                vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));
        
                // Base Case: When i == j, it's a single operand
                for (int i = 0; i < n; i += 2) {
                    dp[i][i][1] = (s[i] == 'T');  // True case
                    dp[i][i][0] = (s[i] == 'F');  // False case
                }
        
                // Length of the substring (only considering odd lengths since operators are at odd indices)
                for (int len = 3; len <= n; len += 2) {  // len starts from 3 and increases by 2
                    for (int i = 0; i <= n - len; i += 2) {
                        int j = i + len - 1;  // Right boundary of substring
        
                        for (int k = i + 1; k < j; k += 2) {  // Operator positions
                            int lt = dp[i][k - 1][1];
                            int lf = dp[i][k - 1][0];
                            int rt = dp[k + 1][j][1];
                            int rf = dp[k + 1][j][0];
        
                            if (s[k] == '&') {
                                dp[i][j][1] += (lt * rt);
                                dp[i][j][0] += (lt * rf) + (lf * rt) + (lf * rf);
                            } 
                            else if (s[k] == '|') {
                                dp[i][j][1] += (lt * rt) + (lt * rf) + (lf * rt);
                                dp[i][j][0] += (lf * rf);
                            } 
                            else if (s[k] == '^') {
                                dp[i][j][1] += (lt * rf) + (lf * rt);
                                dp[i][j][0] += (lt * rt) + (lf * rf);
                            }
                        }
                    }
                }
        
                return dp[0][n - 1][1];  // Return the number of ways to evaluate the whole expression to True
            }
        };
        