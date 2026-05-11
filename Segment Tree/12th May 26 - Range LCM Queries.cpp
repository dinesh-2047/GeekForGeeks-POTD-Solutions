// Range LCM Queries

class Solution {
public:
    using ll = long long;

    vector<ll> seg;
    int n;

    void build(int idx, int low, int high, vector<int>& arr) {

        if (low == high) {
            seg[idx] = arr[low];
            return;
        }

        int mid = (low + high) / 2;

        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);

        seg[idx] = lcm(seg[2 * idx + 1],seg[2 * idx + 2]);
    }

    void update(int idx, int low, int high, int pos, int val) {

        if (low == high) {
            seg[idx] = val;
            return;
        }

        int mid = (low + high) / 2;

        if (pos <= mid)
            update(2 * idx + 1, low, mid, pos, val);
        else
            update(2 * idx + 2, mid + 1, high, pos, val);

        seg[idx] = lcm(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    ll query(int idx, int low, int high,  int l, int r) {

        if (r < low || high < l)
            return 1;

        if (l <= low && high <= r)
            return seg[idx];

        int mid = (low + high) / 2;

        ll left = query(2 * idx + 1, low, mid, l, r);
        ll right = query(2 * idx + 2, mid + 1, high, l, r);

        return lcm(left, right);
    }

    vector<long long> RangeLCMQuery(vector<int> &arr,  vector<vector<int>> &queries) {

        n = arr.size();

        seg.resize(4 * n);

        build(0, 0, n - 1, arr);

        vector<ll> result;

        for (auto &q : queries) {

            int type = q[0];

            if (type == 1) {

                int idx = q[1];
                int val = q[2];

                update(0, 0, n - 1, idx, val);
            }
            else {

                int l = q[1];
                int r = q[2];

                result.push_back(  query(0, 0, n - 1, l, r));
            }
        }

        return result;
    }
};