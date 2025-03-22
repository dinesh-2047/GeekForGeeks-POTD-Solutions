// Decode Ways 

// Approach-1 (Using Recursion + Memoization)
// T.C : O(n) after memoization (without memoization - O(2^n))
// S.C : O(101) ~= O(1)
class Solution {
    public:
        int dp[101];
    
        int solve(int i, string &digits, int &n) {
            if (dp[i] != -1) {
                return dp[i];
            }
    
            if (i == n) {
                return dp[i] = 1; // One valid split done
            }
    
            if (digits[i] == '0') {
                return dp[i] = 0; // Not possible to split
            }
    
            int result = solve(i + 1, digits, n);
    
            if (i + 1 < n) {
                if (digits[i] == '1' || (digits[i] == '2' && digits[i + 1] <= '6'))
                    result += solve(i + 2, digits, n);
            }
    
            return dp[i] = result;
        }
    
        int countWays(string &digits) {
            n = digits.length();
            memset(dp, -1, sizeof(dp));
            return solve(0, digits, n);
        }
    };
    
    // Approach-2 (Bottom-Up Way-1)
    // T.C : O(n)
    // S.C : O(n)
    class Solution {
    public:
        int bottom_up_1(string &digits, int n) {
            vector<int> dp(n + 1, 0);
            // dp[i] = ways to decode string from index i to n
            dp[n] = 1;
    
            for (int i = n - 1; i >= 0; i--) {
                if (digits[i] == '0')
                    dp[i] = 0;
                else {
                    dp[i] = dp[i + 1];
                    if (i + 1 < n && (digits[i] == '1' || (digits[i] == '2' && digits[i + 1] < '7')))
                        dp[i] += dp[i + 2];
                }
            }
            return dp[0];
        }
    
        int countWays(string &digits) {
            n = digits.length();
            return bottom_up_1(digits, n);
        }
    };
    
    // Approach-3 (Using Bottom-Up Way-2)
    // T.C : O(n)
    // S.C : O(n)
    class Solution {
    public:
        int bottom_up_2(string &digits, int n) {
            vector<int> dp(n + 1, 0);
            // dp[i] = ways to decode string of length i
            dp[0] = 1;
            dp[1] = digits[0] == '0' ? 0 : 1;
    
            for (int i = 2; i <= n; i++) {
                if (digits[i - 1] != '0')
                    dp[i] += dp[i - 1];
    
                if (digits[i - 2] == '1' || (digits[i - 2] == '2' && digits[i - 1] < '7'))
                    dp[i] += dp[i - 2];
            }
            return dp[n];
        }
    
        int countWays(string &digits) {
            n = digits.length();
            return bottom_up_2(digits, n);
        }
    };
    
    // Approach-4 (Space Optimized)
    // T.C : O(n)
    // S.C : O(1)
    class Solution {
    public:
        int countWays(string digits) {
            n = digits.length();
            if (n == 1)
                return digits[0] == '0' ? 0 : 1;
            if (digits[0] == '0')
                return 0;
    
            int next = 1, second_next = 1;
    
            for (int i = n - 1; i >= 0; i--) {
                if (digits[i] == '0') continue;
                
                int op1 = next;
                int op2 = 0;
                if (i + 1 < n) {
                    if (digits[i] == '1' || (digits[i] == '2' && digits[i + 1] <= '6')) {
                        op2 = second_next;
                    }
                }
                int curr = op1 + op2;
                second_next = next;
                next = curr;
            }
    
            return next;
        }
    };
    