// Longest Colored Path

class Solution {
public:
    int longestPath(string& s, vector<vector<int>>& edges) {
        int n = s.size();

        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            int u = e[0] - 1;
            int v = e[1] - 1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> comp(n, -1);
        vector<int> ecc(n, 0);
        vector<int> dist(n, 0);

        auto traverse = [&](int src, char color) {
            int far = src;

            vector<pair<int, int>> st;
            st.push_back({src, -1});
            dist[src] = 0;

            while (!st.empty()) {
                auto [u, p] = st.back();
                st.pop_back();

                if (dist[u] > dist[far])
                    far = u;

                for (int v : adj[u]) {
                    if (v == p || s[v] != color)
                        continue;

                    dist[v] = dist[u] + 1;
                    st.push_back({v, u});
                }
            }

            return far;
        };

        int result = 1;
        int id = 0;

        for (int i = 0; i < n; i++) {
            if (comp[i] != -1)
                continue;

            char color = s[i];

            vector<int> nodes;
            vector<int> st = {i};

            comp[i] = id;

            while (!st.empty()) {
                int u = st.back();
                st.pop_back();

                nodes.push_back(u);

                for (int v : adj[u]) {
                    if (s[v] == color && comp[v] == -1) {
                        comp[v] = id;
                        st.push_back(v);
                    }
                }
            }

            int a = traverse(i, color);
            int b = traverse(a, color);

            vector<int> d1(nodes.size());
            vector<int> d2(nodes.size());

            for (int j = 0; j < nodes.size(); j++)
                d1[j] = dist[nodes[j]];

            traverse(b, color);

            for (int j = 0; j < nodes.size(); j++) {
                int u = nodes[j];

                d2[j] = dist[u];

                ecc[u] = max(d1[j], d2[j]) + 1;
                result = max(result, ecc[u]);
            }

            id++;
        }

        for (auto &e : edges) {
            int u = e[0] - 1;
            int v = e[1] - 1;

            if (s[u] != s[v])
                result = max(result, ecc[u] + ecc[v]);
        }

        return result;
    }
};