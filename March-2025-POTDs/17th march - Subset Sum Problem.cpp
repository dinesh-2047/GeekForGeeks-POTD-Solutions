// Subset Sum Problem

// Subset Sum Problem - Multiple Approaches in C++
// Author: Dinesh Bhardwaj

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int n;

  // Approach 1: Recursive (Brute Force) - TLE
  // Time Complexity: O(2^n) - Exponential
  // Space Complexity: O(n) - Recursive stack space
  bool solveRecursive(vector<int> &arr, int sum, int i) {
      if (sum == 0) return true;
      if (i == n || sum < 0) return false;
      
      bool take = solveRecursive(arr, sum - arr[i], i + 1);
      bool not_take = solveRecursive(arr, sum, i + 1);
      
      return take || not_take;
  }
  
  // Approach 2: Memoization (Top-Down DP)
  // Time Complexity: O(n * sum)
  // Space Complexity: O(n * sum) + O(n) (Recursive stack)
  bool solveMemo(vector<int> &arr, int sum, int i, vector<vector<int>> &dp) {
      if (sum == 0) return true;
      if (i == n || sum < 0) return false;
      
      if (dp[i][sum] != -1) return dp[i][sum];
      
      bool take = false;
      if (sum >= arr[i]) take = solveMemo(arr, sum - arr[i], i + 1, dp);
      bool not_take = solveMemo(arr, sum, i + 1, dp);
      
      return dp[i][sum] = take || not_take;
  }
  
  bool isSubsetSumMemo(vector<int>& arr, int sum) {
      n = arr.size();
      vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
      return solveMemo(arr, sum, 0, dp);
  }

  // Approach 3: Tabulation (Bottom-Up DP)
  // Time Complexity: O(n * sum)
  // Space Complexity: O(n * sum)
  bool isSubsetSumTabulation(vector<int>& arr, int sum) {
      n = arr.size();
      vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
      
      for (int i = 0; i <= n; i++) dp[i][0] = true;
      
      for (int i = n - 1; i >= 0; i--) {
          for (int j = 0; j <= sum; j++) {
              if (j == 0) dp[i][j] = true;
              else if (j >= arr[i]) {
                  dp[i][j] = dp[i + 1][j - arr[i]] || dp[i + 1][j];
              } else {
                  dp[i][j] = dp[i + 1][j];
              }
          }
      }
      
      return dp[0][sum];
  }

  // Approach 4: Space Optimized DP (2-row optimization)
  // Time Complexity: O(n * sum)
  // Space Complexity: O(2 * sum) ~ O(sum)
  bool isSubsetSumSpaceOptimized1(vector<int>& arr, int sum) {
      n = arr.size();
      vector<int> prev(sum + 1, false), curr(sum + 1, false);
      prev[0] = curr[0] = true;
      
      for (int i = n - 1; i >= 0; i--) {
          for (int j = 0; j <= sum; j++) {
              if (j >= arr[i]) curr[j] = prev[j - arr[i]] || prev[j];
              else curr[j] = prev[j];
          }
          prev = curr;
      }
      
      return prev[sum];
  }

  // Approach 5: Space Optimized DP (1-row optimization)
  // Time Complexity: O(n * sum)
  // Space Complexity: O(sum)
  bool isSubsetSumSpaceOptimized2(vector<int>& arr, int sum) {
      n = arr.size();
      vector<int> dp(sum + 1, false);
      dp[0] = true;
      
      for (int i = 0; i < n; i++) {
          for (int j = sum; j >= arr[i]; j--) {
              dp[j] = dp[j - arr[i]] || dp[j];
          }
      }
      
      return dp[sum];
  }
};
