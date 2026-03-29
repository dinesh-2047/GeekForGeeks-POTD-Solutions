// Partitions with Given Difference

class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(vector<int>& arr, int i, int sum) {
        if (i == 0) {
            if (sum == 0 && arr[0] == 0) return 2;
            if (sum == 0 || arr[0] == sum) return 1;
            return 0;
        }

        if (dp[i][sum] != -1) return dp[i][sum];

        int not_take = solve(arr, i - 1, sum);

        int take = 0;
        if (arr[i] <= sum)
            take = solve(arr, i - 1, sum - arr[i]);

        return dp[i][sum] = take + not_take;
    }

    int countPartitions(vector<int>& arr, int d) {
        int total = accumulate(arr.begin(), arr.end(), 0);

        if ((total + d) % 2) return 0;

        int target = (total + d) / 2;

        int zeroCount = count(arr.begin(), arr.end(), 0);

        vector<int> f;
        for (int x : arr) {
            if (x != 0) f.push_back(x);
        }

        n = f.size();
        dp.assign(n, vector<int>(target + 1, -1));

        int ways = solve(f, n - 1, target);

        return ways * (1 << zeroCount);
    }
};