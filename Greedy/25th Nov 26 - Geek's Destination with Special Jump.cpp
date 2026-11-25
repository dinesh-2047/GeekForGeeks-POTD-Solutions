// Geek's Destination with Special Jump


class Solution {
    using ll = long long;

    static const ll MOD = 1e9 + 7;

    ll a, b, c;

    ll getTime(ll x) {
        ll k = 0;

        if (x > a) {
            k = (x - a + c - 1) / c;
        }

        return x + 2 * b * k;
    }

    ll ceilSum(ll n) {
        if (n <= 0) return 0;

        ll q = n / c;
        ll rem = n % c;

        return c * q * (q + 1) / 2
               + rem * (q + 1);
    }

    ll prefix(ll x) {
        if (x <= 0) return 0;

        ll ans = 0;
        ll upto = min(x, a);

        ans += upto * (upto + 1) / 2 + upto;

        if (x > a) {
            ll n = x - a;

            ans += (x * (x + 1) - a * (a + 1)) / 2;
            ans += n;
            ans += 2 * b * ceilSum(n);
        }

        return ans;
    }

public:
    int minTime(int A, int B, int d, int l, int r) {
        a = A;
        b = B;
        c = a - b;

        ll normal = getTime(d);

        ll L = d - r;
        ll R = d - l;

        ll low = L, high = R;
        ll pos = L - 1;

        while (low <= high) {
            ll mid = low + (high - low) / 2;

            if (getTime(mid) + 1 <= normal) {
                pos = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        ll ans = 0;

        if (pos >= L) {
            ans += prefix(pos) - prefix(L - 1);
        }

        if (pos < R) {
            ans += (R - max(L, pos + 1) + 1) * normal;
        }

        return ans % MOD;
    }
};
