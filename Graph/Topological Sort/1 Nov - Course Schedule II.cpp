// Course Schedule II


class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        
        unordered_map<int, list<int>>adj; 
        
        vector<int>indegree(n , 0);
        
        for(auto &p : prerequisites){
            int u = p[0];
            int v = p[1];
            
            adj[v].push_back(u);
            indegree[u]++;
        }
        
        queue<int>q; 
        
        for(int i = 0 ; i  < n; i++){
            if(indegree[i] == 0 ) q.push(i);
        }
        
        vector<int>result; 
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            result.push_back(curr);
            
            for(auto &nbr : adj[curr]){
                indegree[nbr]--;
                if(indegree[nbr] == 0 ){
                    q.push(nbr);
                }
            }
        }
        if(result.size() == n ) return result; 
        else return {};
    }
};