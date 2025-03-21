// Stickler Thief II

// Approach 1 Rec/
class Solution {
    public:
  
    int solve(vector<int>&arr, int i, int n  ){
        if(i>=n) return 0 ; 
        
        int take = arr[i] + solve(arr, i + 2, n );
        int not_take  = solve(arr, i + 1, n);
        
        return max(take, not_take);
    }
    
    
      int maxValue(vector<int>& arr) {
         
          arr.push_back(arr[0]);
           int n = arr.size();
          
          return max(solve(arr, 0, n-2), solve(arr, 1,n-1 ));
          
      }
  };
  


// REc+ memo 

class Solution {
    public:
  
    int solve(vector<int>&arr, int i, int n,vector<int>&dp  ){
        if(i>=n) return 0 ; 
        
         if(dp[i] != -1) return dp[i];
        
        int take = arr[i] + solve(arr, i + 2, n ,dp);
        int not_take  = solve(arr, i + 1, n,dp);
        
        return dp[i] = max(take, not_take);
    }
    
    
      int maxValue(vector<int>& arr) {
         
          arr.push_back(arr[0]);
           int n = arr.size();
          vector<int>dp1(n+1, -1), dp2(n+1,-1);
          return max(solve(arr, 0, n-2,dp1), solve(arr, 1,n-1,dp2 ));
          
      }
  };
  


// Tabulation 

int solveTab(vector<int> &arr, int n , int st ){
    vector<int>dp(n+1, 0);
    
    for(int i = n-1 ; i>=st; i-- ){
        if(i+2<n)
        dp[i] = max(arr[i] + dp[i+2], dp[i+1]);
        else dp[i] = max(arr[i] + 0 , dp[i+1]);
    }
    
    return dp[st];
}


  int maxValue(vector<int>& arr) {
     
      arr.push_back(arr[0]);
       int n = arr.size();
     
      
      return max(solveTab(arr, n-2,0 ), solveTab(arr, n-1, 1));
      
  }
};




// so 
int so(vector<int>&arr, int n , int st ){
    int curr = 0 ; 
    int next = 0 ; 
    int second_next = 0 ; 
    
    
    for(int i = n -1; i >= st; i--){
        if(i+2<n)
        curr = max(arr[i]+second_next, next);
        else
        curr = max(arr[i] + 0, next);
        
        second_next = next; 
        next = curr;
    }
    return next; 
    
}


  int maxValue(vector<int>& arr) {
     
      arr.push_back(arr[0]);
       int n = arr.size();
      
      return max(so(arr, n-2,0 ), so(arr, n-1, 1));
      
  }
};
