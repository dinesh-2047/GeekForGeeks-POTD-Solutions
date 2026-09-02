// Max Adjacent Diffs Sum with 1 Replacements

class Solution {
public:
    int n;
    vector<vector<long long>> dp;

    long long solve(vector<int>& arr, int i, int prev) {
        if (i == n)
            return 0;

        if (dp[i][prev] != -1)
            return dp[i][prev];

        long long prevVal = (prev == 0 ? 1 : arr[i - 1]);

        long long changeToOne =
            abs(prevVal - 1) +
            solve(arr, i + 1, 0);

        long long keep =
            abs(prevVal - arr[i]) +
            solve(arr, i + 1, 1);

        return dp[i][prev] = max(changeToOne, keep);
    }

    int maxDiffSum(vector<int>& arr) {
        n = arr.size();

        if (n <= 1)
            return 0;

        dp.assign(n, vector<long long>(2, -1));

        long long firstOne = solve(arr, 1, 0);
        long long firstOriginal = solve(arr, 1, 1);

        return max(firstOne, firstOriginal);
    }
};

