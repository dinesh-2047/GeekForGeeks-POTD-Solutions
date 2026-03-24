// Course Schedule I

class Solution {
  public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        unordered_map<int , list<int>>adj; 
        
        vector<int>indegree(n, 0);
        
        for(auto &p : prerequisites){
            int u = p[0];
            int v = p[1];
            
            adj[v].push_back(u);
            indegree[u]++;
        }
        
        
        queue<int>q; 
        for(int i = 0 ; i  < n; i++){
            if(indegree[i] == 0 ){
                q.push(i);
            }
        }
        
        int count = 0 ; 
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            
            for(auto &nbr :adj[node]){
                indegree[nbr]--;
                if(indegree[nbr] == 0 ){
                    q.push(nbr);
                }
            }
        }
        return count == n; 
    }
};

