// Shortest Cycle

class Solution {
  public:
  
    int helper(vector<vector<int>>&adj, int vertex)
    {
        queue<pair<int,int>> q;
        q.push({vertex,-1});
        int count = 0;
        while(!q.empty())
        {
            int l = q.size();
            while(l--)
            {
                int node = q.front().first;
                int prev = q.front().second;
                q.pop();
                for(int i=0;i<adj[node].size();i++)
                {
                    int nn = adj[node][i];
                    if(nn!=prev)
                    {
                        if(nn==vertex)
                            return(count);
                        q.push({nn,node});
                    }
                }
            }
            count++;
        }
        return(-1);
    }
  
    int shortCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            if(u==v)
            {
                return(1);
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = INT_MAX;
        for(int i=0;i<V;i++)
        {
            int temp = helper(adj,i);
            if(temp!=-1)
            {
                ans = min(ans,temp);
            }
        }
        if(ans==INT_MAX)
        {
            return(-1);
        }
        return(ans+1);
        
    }
};