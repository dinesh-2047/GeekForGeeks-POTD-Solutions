// Minimum Cost Pizza Selection


class Solution {
public:
    int solve(int x, int s, int m, int l, int cs, int cm, int cl,
              vector<int>& dp) {

        if (x <= 0)
            return 0;

        if (dp[x] != -1)
            return dp[x];

        return dp[x] = min({
            cs + solve(x - s, s, m, l, cs, cm, cl, dp),
            cm + solve(x - m, s, m, l, cs, cm, cl, dp),
            cl + solve(x - l, s, m, l, cs, cm, cl, dp)
        });
    }

    int minimumCost(int x, int s, int m, int l, int cs, int cm, int cl) {
        vector<int> dp(x + 1, -1);

        return solve(x, s, m, l, cs, cm, cl, dp);
    }
};