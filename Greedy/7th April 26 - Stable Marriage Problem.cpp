// Stable Marriage Problem


class Solution {
  public:
    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women) {
        int n = men.size();
        
        vector<vector<int>>rank(n, vector<int>(n));
        
        for(int i = 0 ; i  < n; i++){
            for(int j = 0 ; j  < n; j++){
                rank[i][women[i][j]] = j; 
            }
        }
        
        vector<int>result(n,-1);
        vector<int>woman(n,-1);
        vector<int>next(n,0);
        queue<int>q; 
        
        for(int i = 0 ; i  < n; i++) q.push(i);
        
        while(!q.empty()){
            int m = q.front();
            q.pop();
            
            int w = men[m][next[m]++];
            int curr = woman[w];
            
            if(curr == -1 || rank[w][m] < rank[w][curr]){
                woman[w] = m; 
                result[m] = w; 
                
                if(curr != -1) q.push(curr);
                
                
            }
            else q.push(m);
        }
        return result; 
        
        
    }
};