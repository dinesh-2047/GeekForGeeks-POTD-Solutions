// 2D Submatrix Sum Queries


class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        // Build 2D prefix sum array
        vector<vector<long long>> prefix(n + 1, vector<long long>(m + 1, 0));
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                prefix[i][j] = mat[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
        
        vector<int> result;
        
        // Process each query
        for(auto& query : queries) {
            int r1 = query[0];
            int c1 = query[1];
            int r2 = query[2];
            int c2 = query[3];
            
            // Convert to 1-indexed for prefix array
            r1++; c1++; r2++; c2++;
            
            // Calculate submatrix sum using inclusion-exclusion principle
            long long sum = prefix[r2][c2] - prefix[r1-1][c2] - prefix[r2][c1-1] + prefix[r1-1][c1-1];
            
            result.push_back((int)sum);
        }
        
        return result;
    }
};

