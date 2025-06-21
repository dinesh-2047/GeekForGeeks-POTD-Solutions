// Largest Divisible Subset

class Solution {
public:
    vector<int> largestSubset(vector<int>& arr) {
        sort(arr.rbegin(), arr.rend());
        int n = arr.size();
        
        vector<int> dp(n, 1);
        vector<int> prevIdx(n, -1);

        int maxLen = 1;
        int lastChoosenIdx = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] % arr[i] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prevIdx[i] = j;
                }
            }

            if (dp[i] > maxLen) {
                maxLen = dp[i];
                lastChoosenIdx = i;
            }
        }

        vector<int> result;
        while (lastChoosenIdx != -1) {
            result.push_back(arr[lastChoosenIdx]);
            lastChoosenIdx = prevIdx[lastChoosenIdx];
        }

      
        return result;
    }
};
