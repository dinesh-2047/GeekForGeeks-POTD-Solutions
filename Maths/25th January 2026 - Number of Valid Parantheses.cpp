// Number of Valid parantheses


class Solution {
  public:
    int result;

    void solve(int o, int c) {
        if (o == 0 && c == 0) {
            result++;
            return;
        }

        // Add '(' if available
        if (o > 0) {
            solve(o - 1, c);
        }

        // Add ')' only if it won't break validity
        if (c > o) {
            solve(o, c - 1);
        }
    }

    int findWays(int n) {
        if (n % 2 == 1) return 0;

        result = 0;
        solve(n / 2, n / 2);
        return result;
    }
};





// Approach 2 (Using Catalan Number)
class Solution {
  public:
  using ll = long long ;
   ll catalan(int n) {
    ll result = 1;
    for (int i = 0; i < n; i++) {
        result = result * (2*n - i) / (i + 1);
    }
    return result/(n + 1);
}
    int findWays(int n) {
        if(n%2 == 1) return 0 ; 
        return catalan(n/2);
    }
};