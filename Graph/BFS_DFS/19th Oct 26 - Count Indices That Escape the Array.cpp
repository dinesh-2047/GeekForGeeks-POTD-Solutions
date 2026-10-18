// Count Indices That Escape the Array

class Solution {
public:
    int n;
    vector<int> vis;

    int dfs(vector<int>& arr, int i) {
        if (i < 0 || i >= n)
            return 1;

        if (arr[i] == 0)
            return vis[i] = 0;

        if (vis[i] != -1)
            return vis[i];

        vis[i] = 0;

        int next = dfs(arr, i + arr[i]);

        return vis[i] = next;
    }

    int goodIndices(vector<int>& arr) {
        n = arr.size();
        vis.assign(n, -1);

        for (int i = 0; i < n; i++) {
            if (vis[i] == -1)
                dfs(arr, i);
        }

        return accumulate(vis.begin(), vis.end(), 0);
    }
};