// Minimum cost to connect all houses in a city



class Solution {
  public:
    int minCost(vector<vector<int>>& houses) {
        int n = houses.size();
        
        unordered_map<int, list<pair<int , int>>>adj; 
        for(int i= 0 ; i<n; i++){
            for(int j = i+1; j<n; j++){
                int x1 = houses[i][0];
                int y1 = houses[i][1];
                
                int x2 = houses[j][0];
                int y2 = houses[j][1];
                
                int d = abs(x1-x2) + abs(y1 - y2);
                adj[i].push_back({j,d});
                adj[j].push_back({i,d});
            }
        }
        
        priority_queue<pair<int, int>, vector<pair<int , int>>, greater<>>pq; 
        
        pq.push({0,0});
        
        vector<bool>inMST(n, false);
        
        int sum = 0; 
        
        while(!pq.empty()){
            auto p  = pq.top();
            pq.pop();
            
            int wt = p.first; 
            int node = p.second ; 
            
            if(inMST[node] == true) continue;
            
            inMST[node] = true; 
            sum+=wt; 
            
            for(auto &temp : adj[node]){
                int nbr = temp.first; 
                int w = temp.second; 
                
                if(inMST[nbr] == false){
                    pq.push({w,nbr});
                }
            }
           
        }
         return sum ;
        
    }
        
    };


