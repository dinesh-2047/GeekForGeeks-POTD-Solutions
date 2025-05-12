// nCr

// Approach 1 Binary exponentiation 

class Solution {
  public:
  const int m = 1e9 + 7;

  long long power(long long a, long long b){
      if(b==0) return 1; 
      
      long long half = power(a, b/2) % m;
      long long result = (half * half) % m;
      
      if(b % 2 == 1){
          result = (result * a) % m;
      }
      
      return result; 
  }

  int nCr(int n, int r) {
       if(n < r) return 0;
     
       vector<long long> fact(n+1, 0);
       fact[0] = 1;
       
       for(int i = 1 ; i <= n; i++){
           fact[i] = (fact[i-1] * i) % m;
       }
       
       long long a = fact[n];
       long long b = (fact[r] * fact[n-r]) % m;
       
       return (a * power(b, m - 2)) % m;
  }
};



// Approach 2 Dp rec + memo 

class Solution {
  public:
  int solve(int n , int r, vector<vector<int>> &dp){
        if(n==r || r==0) return 1; 
        
        if(dp[n][r]!=-1) return dp[n][r];
        int include = solve(n-1, r-1,dp);
        int exclude = solve(n-1, r,dp);
        
        return dp[n][r] = include + exclude;
  }
    int nCr(int n, int r) {
        if(n<r) return 0 ; 
        vector<vector<int>>dp(n+1, vector<int>(r+1,-1));
        
        return solve(n,r,dp);
      
        
    }
};



//Approach 3 rec -> tabulation 
class Solution {
  public:

    int nCr(int n, int r) {
        if(n<r) return 0 ; 
        vector<vector<int>>dp(n+1, vector<int>(r+1,0));
        
        for(int i = 1 ; i<=n; i++){
            for(int j = 0 ; j<=r ; j++){
                if(j==0 || i==j ) dp[i][j]=1;
                else {
                    dp[i][j] = dp[i-1][j-1]  + dp[i-1][j];
                }
            }
        }
      
        return dp[n][r];
    }
};




//Approach 4 so
class Solution {
  public:

    int nCr(int n, int r) {
        if(n<r) return 0 ; 
        vector<int>prev(n+1, 0);
        vector<int>curr(n+1, 0);
        
       prev[0] = curr[0] = 1;
        
        for(int i = 1 ; i<=n; i++){
            for(int j = 0 ; j<=r ; j++){
                if(j==0 || i==j ) curr[j]=1;
                else {
                    curr[j] = prev[j-1]  + prev[j];
                }
            }
            prev = curr; 
        }
      
        return prev[r];
    }
};




// Approach 5 simple calcluation 

class Solution {
  public:
    int nCr(int n, int r) {
        if(n<r) return 0 ; 
        if(r==0) return 1; 
        r = min(r, n-r);
        long long ncr = 1;
      for (int i = 0; i < r; i++) {
     ncr = (ncr * (n - i)) / (i + 1);
}
 return int(ncr);
        
    }
};