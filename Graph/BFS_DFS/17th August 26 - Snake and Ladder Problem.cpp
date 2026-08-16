// Snake and Ladder Problem

class Solution {
  public:
    int minThrows(int N, vector<int>& lad, vector<int>& sn) {
        int n = N * N; 
       vector<int> jump(n + 1, -1);
       
       for(int i = 0 ; i < lad.size(); i+=2){
           jump[lad[i]] = lad[i + 1];
       }
       
       for(int i = 0 ; i < sn.size(); i+=2){
           jump[sn[i]] = sn[i + 1];
       }
       
       vector<int> dist(n + 1, -1);
       
       dist[1] = 0;
       queue<int> q; 
       q.push(1);
       
       while(!q.empty()){
           auto curr = q.front();
           q.pop();
           if(curr == n){
               return dist[curr];
           }
           
           for(int dice = 1; dice <= 6; dice++){
               int next = curr+ dice; 
               if(next > n ) continue; 
               if(jump[next]!=-1) next = jump[next];
               if(dist[next] == -1){
                   dist[next] = dist[curr] + 1 ; 
                   q.push(next);
               }
           }
       }
       return -1; 
        
    }
};