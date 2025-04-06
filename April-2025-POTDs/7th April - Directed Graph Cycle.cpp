// Directed Graph Cycle 


// Approach 1 DFS 


class Solution {
    public:
    bool checkCycle(unordered_map<int , list<int>> &adj , int node , vector<bool>&visited, vector<bool> &inRecursion ){
        visited[node] = true; 
        inRecursion[node] = true; 
        
        for(auto &nbr : adj[node]){
          
            
            if(!visited[nbr]){
                if(checkCycle(adj , nbr , visited, inRecursion)) return true; 
            }
            else if(inRecursion[nbr] == true)  return true; 
        } 
        inRecursion[node] = false; 
        return false; 
    }
    
      bool isCyclic(int V, vector<vector<int>> &edges) {
          unordered_map<int , list<int>>adj ; 
          
          for(auto &edge :edges){
              int u = edge[0];
              int v = edge[1];
              adj[u].push_back(v);
          }
          
          vector<bool>visited(V+1, false);
          vector<bool>inRecursion(V+1, false);
          for(int i = 0 ; i<V; i++){
              if(!visited[i]){
                  if(checkCycle(adj , i , visited,inRecursion)) return true; 
              }
          }
          return false; 
          
      }
  };


//Approach 2 using toposort bfs 

class Solution {
    public:
    
    
      bool isCyclic(int V, vector<vector<int>> &edges) {
          unordered_map<int , list<int>>adj ; 
          vector<int>indegree(V, 0);
          for(auto &edge :edges){
              int u = edge[0];
              int v = edge[1];
              adj[u].push_back(v);
              indegree[v]++;
          }
          int cnt = 0 ;
           queue<int>q; 
           for(int i= 0 ; i<V; i++){
               if(indegree[i] == 0 ) q.push(i);
           }
           
           while(!q.empty()){
               auto curr = q.front();
               q.pop();
               cnt++;
               
               for(auto &nbr : adj[curr]){
                   indegree[nbr]--;
                   if(indegree[nbr]==0){
                       
                       q.push(nbr);
                   }
               }
           }
        if(cnt == V) return false; 
       else  return true; 
          
      }
  };