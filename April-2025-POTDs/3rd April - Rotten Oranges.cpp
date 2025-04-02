// Rotten Oranges 

class Solution {
    public:
    vector<vector<int>>directions = {{0,1},{0,-1},{1,0},{-1,0}};
      int orangesRotting(vector<vector<int>>& mat) {
         int m = mat.size();
         int n = mat[0].size();
         
         
         int freshOranges = 0 ; 
         queue<pair<int , int>>q;
         
         for(int i = 0 ; i<m; i++){
             for(int j = 0 ; j<n; j++){
                 if(mat[i][j]==2){
                     q.push({i,j});
                 }
                  if (mat[i][j]==1) freshOranges++;
             }
         }
         if(freshOranges == 0) return 0 ;
         int minutes = 0 ; 
         while(!q.empty()){
             int N = q.size();
             while(N--){
                 auto curr = q.front();
                 q.pop();
                 int i = curr.first;
                 int j = curr.second; 
                 for(auto &dir : directions ){
                     int newi = i  + dir[0];
                     int newj = j + dir[1];
                     
                     if(newi<m && newi >= 0 && newj < n && newj >=0 ){
                         if(mat[newi][newj]==1){
                             mat[newi][newj] = 2;
                             freshOranges--;
                             q.push({newi, newj});
                         }
                     }
                 }
             }
             minutes++;
         }
         
         if(freshOranges==0) return minutes-1;
         else return -1; 
          
      }
  };
  