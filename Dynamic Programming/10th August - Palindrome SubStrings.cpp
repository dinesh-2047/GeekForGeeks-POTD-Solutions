// Palindrome SubStrings


// Approach 1 

class Solution {
  public:
    int countPS(string &s) {
        // code here
        int n = s.length();
        int count = 0 ; 
        vector<vector<bool>>dp(n+1, vector<bool>(n+1, false));
        
        for(int l = 1; l <= n ;l++){
            for(int i = 0 ; i + l-1 <n;  i++){
                int j = i + l- 1; 
                if(i==j) dp[i][j] = true; 
                else if(i+1 == j ){
                    dp[i][j] = (s[i]==s[j]); 
                }
                
                else {
                    dp[i][j] = (s[i] ==s[j]) && (dp[i+1][j-1]);
                }
                
                if(i!=j && dp[i][j]) count++;
            }
            
            
        }
        return count; 
    }
};











//Approach 2 
class Solution {
  public:
  int n ; 
  void check (int i , int j , int &count , string &s){
      if (i == j ) {
          j=i+1;
          i=i-1;
           
      }
      
      while(i >= 0 && j < n && s[i] == s[j]){
          count++;
          i--;
          j++;
      }
  }
  
  
    int countPS(string &s) {
       int count = 0 ; 
       n = s.length();
       
       for(int i = 0 ; i < n; i++){
          check(i, i , count, s);
           check(i, i+1, count , s);
           
       }
       return count ; 
    }
};