// Minimum Multiplications to reach End

class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        int n = arr.size();
        
        vector<int> dist(1000, -1);
        
        queue<int> q; 
        q.push(start);
        dist[start]= 0; 
     
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            
            if(curr == end){
               return dist[end];
            }
            
            for(auto &x : arr){
                int nbr = (x * curr)%1000; 
                
                if(dist[nbr] == -1){
                    dist[nbr] = dist[curr] + 1; 
                    q.push(nbr);
                }
            }
        }
        
         return -1; 
    }
};