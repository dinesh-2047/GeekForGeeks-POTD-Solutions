// Range GCD Queries

class Solution {
public:
    vector<int> seg;

    void build(int node, int l, int r, vector<int>& arr) {
        if (l == r) {
            seg[node] = arr[l];
            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * node, l, mid, arr);
        build(2 * node + 1, mid + 1, r, arr);

        seg[node] = gcd(seg[2 * node], seg[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            seg[node] = val;
            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid)
            update(2 * node, l, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, r, idx, val);

        seg[node] = gcd(seg[2 * node], seg[2 * node + 1]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr)
            return 0;

        if (ql <= l && r <= qr)
            return seg[node];

        int mid = l + (r - l) / 2;

        int leftGCD = query(2 * node, l, mid, ql, qr);
        int rightGCD = query(2 * node + 1, mid + 1, r, ql, qr);

        return gcd(leftGCD, rightGCD);
    }

    vector<int> processQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();

        seg.resize(4 * n);
        build(1, 0, n - 1, arr);

        vector<int> result;

        for (auto &q : queries) {
            if (q[0] == 0) {
                result.push_back(query(1, 0, n - 1, q[1], q[2]));
            } else {
                update(1, 0, n - 1, q[1], q[2]);
            }
        }

        return result;
    }
};