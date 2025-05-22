// Dice throw


// Rec + memo 

class Solution {
  public:
  int faces ; 
  int solve(int n , int x, vector<vector<int>> &dp ){
      if(n==0 && x == 0 ) return 1; 
      
      if(n==0) return 0 ; 
      
      if(dp[n][x]!=-1) return dp[n][x];
      
      int count = 0; 
      
      for(int j= 1; j <= faces; j++){
        if(x-j >= 0)  count+= solve(n-1 , x-j,dp);
          
      }
      return dp[n][x] = count ;
  }
  
    int noOfWays(int m, int n, int x) {
        faces = m ;
        vector<vector<int>>dp(n+1, vector<int>(x+ 1, -1));
      return  solve(n ,x, dp );
        
    }
};






//Tabulation 


class Solution {
  public:

    int noOfWays(int m, int n, int x) {
       
        vector<vector<int>>dp(n+1, vector<int>(x+ 1, 0));
          dp[0][0] = 1;
         for(int i = 1 ; i<=n; i++){
             for(int j = 1; j<=x; j++){
                 int count = 0 ; 
                 
                 for(int k = 1; k<=m; k++){
                     if(j-k >= 0) 
                     count += dp[i-1][j-k];
                 }
                 dp[i][j] = count; 
             }
         }
     
     return dp[n][x];
        
    }
};




// Space optimization 
class Solution {
  public:

    int noOfWays(int m, int n, int x) {
       
       
        vector<int>prev(x+1, 0);
        vector<int>curr(x+1,0);
        prev[0] = 1;
         for(int i = 1 ; i<=n; i++){
             for(int j = 1; j<=x; j++){
                 int count = 0 ; 
                 
                 for(int k = 1; k<=m; k++){
                     if(j-k >= 0) 
                     count += prev[j-k];
                 }
                 curr[j] = count; 
             }
             prev = curr ;
         }
     
     return prev[x];
        
    }
};