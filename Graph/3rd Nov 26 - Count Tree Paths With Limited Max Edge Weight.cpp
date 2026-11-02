// Count Tree Paths With Limited Max Edge Weight


class Solution {
    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }

public:
    vector<int> maximumWeight(int n, vector<vector<int>> edges, vector<int>& queries) {

        sort(edges.begin(), edges.end(), cmp);

        int q = queries.size();

        vector<pair<int, int>> qs;

        for (int i = 0; i < q; i++) {
            qs.push_back({queries[i], i});
        }

        sort(qs.begin(), qs.end());

        parent.resize(n + 1);
        sz.assign(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        vector<int> result(q);
        long long total = 0;

        int j = 0;

        for (auto [weight, idx] : qs) {

            while (j < edges.size() && edges[j][2] <= weight) {

                int pu = find(edges[j][0]);
                int pv = find(edges[j][1]);

                if (pu != pv) {

                    total += 1LL * sz[pu] * sz[pv];

                    if (sz[pu] < sz[pv])
                        swap(pu, pv);

                    parent[pv] = pu;
                    sz[pu] += sz[pv];
                }

                j++;
            }

            result[idx] = total;
        }

        return result;
    }
};