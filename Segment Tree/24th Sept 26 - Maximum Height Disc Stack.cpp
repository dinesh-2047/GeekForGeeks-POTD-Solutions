// Maximum Height Disc Stack

class Solution {
public:
    vector<int> seg;

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l)
            return 0;

        if (l <= start && end <= r)
            return seg[node];

        int mid = (start + end) / 2;

        return max(
            query(2 * node, start, mid, l, r),
            query(2 * node + 1, mid + 1, end, l, r)
        );
    }

    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            seg[node] = max(seg[node], value);
            return;
        }

        int mid = (start + end) / 2;

        if (idx <= mid)
            update(2 * node, start, mid, idx, value);
        else
            update(2 * node + 1, mid + 1, end, idx, value);

        seg[node] = max(seg[2 * node], seg[2 * node + 1]);
    }

    int maxStackHeight(vector<int>& r, vector<int>& h) {
        int n = r.size();

        vector<pair<int,int>> discs;

        for (int i = 0; i < n; i++)
            discs.push_back({r[i], h[i]});

        sort(discs.begin(), discs.end());

        seg.resize(4 * 1001, 0);

        int result = 0;

        for (int i = 0; i < n;) {
            int j = i;

            while (j < n && discs[j].first == discs[i].first)
                j++;

            vector<pair<int,int>> temp;

            for (int k = i; k < j; k++) {
                int height = discs[k].second;

                int previous = query(1, 1, 1000, 1, height - 1);

                int current = previous + height;

                temp.push_back({height, current});

                result = max(result, current);
            }

            for (auto [height, current] : temp)
                update(1, 1, 1000, height, current);

            i = j;
        }

        return result;
    }
};