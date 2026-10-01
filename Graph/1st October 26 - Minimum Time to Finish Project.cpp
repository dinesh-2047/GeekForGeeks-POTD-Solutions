// Minimum Time to Finish Project

class Solution {
  public:
    int minTime(vector<int> &duration, vector<vector<int>> &dependencies) {
        int n = duration.size();

        unordered_map<int, list<int>> adj;
        vector<int> indegree(n, 0);

        for (auto &edge : dependencies) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        vector<int> finish(n, 0);
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                finish[i] = duration[i];
            }
        }

        int count = 0;
        int result = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            count++;
            result = max(result, finish[u]);

            for (int v : adj[u]) {
                finish[v] = max(finish[v], finish[u] + duration[v]);
                indegree[v]--;

                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        if (count != n)
            return -1;

        return result;
    }
};