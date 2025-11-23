// Maximum Stone Removal

class Solution {
  public:
void dfs(vector<vector<int>>& stones, vector<int>& vis, int node) {
        vis[node] = 1;
        for (int i = 0; i < stones.size(); i++) {
            if (!vis[i] && (stones[i][0] == stones[node][0] || stones[i][1] == stones[node][1])) {
                dfs(stones, vis, i);
            }
        }
    }

    int maxRemove(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> vis(n, 0);
        int group = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(stones, vis, i);
                group++;
            }
        }
        
        return n - group;
        
    }
};