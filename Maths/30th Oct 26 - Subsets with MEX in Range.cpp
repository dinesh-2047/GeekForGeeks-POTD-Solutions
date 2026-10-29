// Subsets with MEX in Range

class Solution {
public:
    int cntSubsets(vector<int> &arr, int l, int r) {
        const long long MOD = 1000000007;
        int n = arr.size();

        vector<int> freq(n + 2, 0);

        for (int x : arr)
            freq[x]++;

        vector<long long> pow2(n + 1, 1);

        for (int i = 1; i <= n; i++)
            pow2[i] = pow2[i - 1] * 2 % MOD;

        vector<int> suffix(n + 3, 0);

        for (int i = n; i >= 0; i--)
            suffix[i] = suffix[i + 1] + freq[i];

        long long result = 0;
        long long ways = 1;

        for (int k = 0; k <= r; k++) {
            if (k >= l) {
                long long other = pow2[suffix[k + 1]];
                result = (result + ways * other) % MOD;
            }

            if (k == n) break;

            ways = ways * (pow2[freq[k]] - 1 + MOD) % MOD;
        }

        return result;
    }
};