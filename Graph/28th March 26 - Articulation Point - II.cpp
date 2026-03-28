// Articulation Point - II


class Solution {
  public:
void dfs(unordered_map<int, list<int>> &adj , int node , vector<bool> &visited , vector<int> &disc, vector<int> &low , int parent , int &timer, vector<int> &result, vector<bool> &isArticulation){
    
    visited[node] = true; 
    low[node] = timer;
    disc[node] = timer;
    timer++;
    int child = 0 ; 
    for(auto &nbr : adj[node]){
        if(nbr == parent) continue; 
        if(!visited[nbr]){
            dfs(adj , nbr, visited, disc, low , node, timer, result,isArticulation);
            low[node] = min(low[node], low[nbr]);
            
            if(low[nbr] >= disc[node] && parent!=-1) isArticulation[node] = true;
            child++;
        }
        else{
            low[node] = min(low[node], disc[nbr]);
        }
    }
    if(child>1 && parent == -1) {
        isArticulation[node] = true; 
    }
}
  
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        
        unordered_map<int, list<int>>adj; 
        
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool>visited(V,false);
        vector<int>disc(V,-1);
        vector<int>low(V,-1);
        int parent = - 1; 
        int timer = 0 ; 
        vector<bool>isArticulation(V,false);
        vector<int>result;
        for(int i = 0 ; i<V; i++){
            if(!visited[i]){
                dfs(adj , i, visited , disc , low , parent , timer, result,isArticulation );
            }
        }
        for(int i = 0 ; i<V; i++){
            if(isArticulation[i]==true) result.push_back(i);
        }
        if(result.empty()) return {-1};
        else return result; 
        
    }
};

