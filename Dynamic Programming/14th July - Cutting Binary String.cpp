// Cutting Binary String

class Solution {
  public:
  int n ;
  bool isPowerOfFive(long long num){
      while(num > 1){
          if(num%5!=0) return false; 
          num/=5;
      }
      return true; 
  }
  
  int solve(string &s, int i, vector<int> &dp ){
         if(i >= n ) return 0; 
         if(s[i] == '0' ) return -1 ; 
         if(dp[i]!=-2) return dp[i];
     
   
      int minCount = INT_MAX;
     
      long long num = 0 ; 
      
      for(int j = i ; j < s.length(); j++){
          
              num = num *2 + (s[j] - '0'); 
              if(isPowerOfFive(num)){
                 
                  int next = solve(s, j + 1, dp);
                  if (next != -1) {
                    minCount = min(minCount, 1 + next);
                
              }
          }
          
      }
      if(minCount == INT_MAX) return dp[i] = -1; 
      else return dp[i] =  minCount; 
      
      
  }
  
    int cuts(string s) {
        n = s.length();
         if(s[0]=='0' || s[n-1] == '0' || n==0) return -1; 
         vector<int>dp(n+ 1, -2);
        
        return solve(s, 0 , dp);
        
    }
};