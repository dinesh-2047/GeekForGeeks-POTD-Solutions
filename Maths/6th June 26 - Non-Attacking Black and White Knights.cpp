// Non-Attacking Black and White Knights


class Solution {
public:
    long long numOfWays(int n, int m) {
        long long N = 1LL * n * m;
        long long attacks = 4LL * (n - 1) * (m - 2) + 4LL * (n - 2) * (m - 1);
        return N * (N - 1) - attacks;
    }
};