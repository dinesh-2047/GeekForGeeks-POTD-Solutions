// Largest Sum Cycle

class Solution {
public:
    int largestSumCycle(vector<int>& edge) {
        int n = edge.size();

        vector<int> vis(n, 0);
        vector<int> pathVis(n, -1);

        int result = -1;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            int node = i;
            int timer = 0;

            while (node != -1 && !vis[node]) {
                vis[node] = 1;
                pathVis[node] = timer++;
                node = edge[node];
            }

            if (node != -1 && pathVis[node] != -1) {
                int sum = 0;
                int curr = node;

                do {
                    sum += curr;
                    curr = edge[curr];
                } while (curr != node);

                result = max(result, sum);
            }

            node = i;

            while (node != -1 && pathVis[node] != -1) {
                pathVis[node] = -1;
                node = edge[node];
            }
        }

        return result;
    }
};