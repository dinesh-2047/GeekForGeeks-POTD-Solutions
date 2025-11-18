// Path With Minimum Effort

class Solution {
  public:
  typedef pair<int , pair<int , int>> P;
  vector<vector<int>>directions = {{0,1},{1,0},{0,-1},{-1,0}};
    int minCostPath(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        priority_queue<P, vector<P>, greater<>>pq; 
        
        vector<vector<int>>dist(m + 1, vector<int>(n + 1, 1e9));
        
        pq.push({0,{0,0}});
        
        dist[0][0] = 0; 
        
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            
            int diff = curr.first; 
            int i = curr.second.first ; 
            int j = curr.second.second; 
            
            if(i == m- 1&& j == n -1  ) return diff; 
            
            for(auto &dir :directions){
                int newi  = i + dir[0];
                int newj = j + dir[1];
                
                if(newi <m && newj < n && newi >= 0 && newj >= 0 ){
                    int new_diff = max(abs(mat[newi][newj] - mat[i][j]), diff);
                    if(dist[newi][newj] > new_diff){
                        dist[newi][newj] = new_diff; 
                        pq.push({new_diff, {newi, newj}});
                    }
                }
            }
        }
        return dist[m-1][n-1];
        
    }
};
