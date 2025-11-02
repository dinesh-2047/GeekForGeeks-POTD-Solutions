// Safe States



class Solution {
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
    vector<int> outdeg(V, 0);
      unordered_map<int, list<int>>adj;
      for(auto z: edges){
          outdeg[z[0]]++;
          adj[z[1]].push_back(z[0]);
      }
      
      queue<int> q;
      for(int i=0;i<V;i++){
        if(outdeg[i] == 0){
            q.push(i);
        }
      }
      
      vector<bool> isSafe(V, false);
      
      while(!q.empty()){
        int x = q.front();
        q.pop();
        isSafe[x] = true;
        
        for(auto z: adj[x]){
            outdeg[z]--;
            if(outdeg[z]==0)
              q.push(z);
            
        }
          
      }
      
      vector<int> ans;
      for(int i=0;i<V;i++){
        if(isSafe[i])
          ans.push_back(i);
      }
      
      return ans;
      
    }
};