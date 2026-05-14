// Special Keyboard


// approach 1 rec + memo ;
class Solution {
  public:
  map<pair<int , pair<int , int>>, int>dp; 
  int solve(int n  , int sl , int l){
      if(n == 0 ) return l;
      
      pair<int , pair<int , int>> key = {n,{sl, l}}; 
      if(dp.count(key)) return dp[key];
      
      int add_one = solve(n - 1, sl, l + 1);
      int paste_if_selected = 0 ; 
      
      if(sl > 0 ){
          paste_if_selected = solve(n -1 , sl, l + sl);
      }
      
      int new_copy = 0 ; 
      if(n >= 2){
          new_copy = solve(n -2 , l , l);
      }
      return dp[key] = max({add_one  , paste_if_selected, new_copy});
  }
    int optimalKeys(int n) {
        return solve(n , 0 , 0);
        
    }
};



// approach 2 tabulation ;
class Solution {
  public:
  
    int optimalKeys(int n) {
        vector<int> dp(n + 1, 0);
        for(int i = 1; i  <= n ; i++){
            dp[i] = dp[i-1]  + 1; 
            for(int j = 1; j  <= i - 3; j++){
                int curr = dp[j] * (i-j-1);
                dp[i]= max(dp[i], curr);
            }
        }
        return dp[n];
    }
};