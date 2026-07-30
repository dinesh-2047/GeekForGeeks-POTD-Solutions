// Subsets with Products of Distinct Primes


class Solution {
public:
    int mod = 1e9 + 7;
    vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    vector<int> freq, mask;
    vector<vector<long long>> dp;

    long long power(long long a, long long b) {
       if(b == 0 ) return 1; 
       long long half = power(a, b/2);
       long long result = (half * half)%mod; 
       
       if(b%2 == 1){
           result = (result * a)%mod;
       }
       return result;
    }

    int fac(int x) {
        int res = 0;
        for (int i = 0; i < 10; i++) {
            int cnt = 0;
            while (x % prime[i] == 0) {
                cnt++;
                x /= prime[i];
            }
            if (cnt > 1) return -1;
            if (cnt == 1) res |= (1 << i);
        }
        return res;
    }

    long long solve(int i, int res) {
        if (i > 30) return res != 0;

        if (dp[i][res] != -1) return dp[i][res];

        long long cnt = solve(i + 1, res);

        if (freq[i] && mask[i] != -1 && !(res & mask[i])) {
            cnt = (cnt + 1LL * freq[i] * solve(i + 1, res | mask[i])) % mod;
        }

        return dp[i][res] = cnt;
    }

    int countSubsets(vector<int> &arr) {
        freq.assign(31, 0);
        mask.assign(31, -1);

        for (int x : arr) freq[x]++;

        for (int i = 2; i <= 30; i++) mask[i] = fac(i);

        dp.assign(31, vector<long long>(1024, -1));

        long long ans = solve(2, 0);
        ans = ans * power(2, freq[1]) % mod;

        return ans;
    }
};