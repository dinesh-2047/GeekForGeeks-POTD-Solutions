// Minimum Deletions


//rec + memo will be added soon 


//tabulation 
class Solution {
  public:
    int minDeletions(string s) {
        // code here
           int n=s.length();
        vector<int>dp(n+3, 0), prev(n+3, 0);
        for(int i=0; i<n; i++){
            for(int j=n-1; j>=0; j--){
                if(s[i]==s[j]){
                    dp[n-j]=1+prev[n-j-1];
                }else{
                    dp[n-j]=max(dp[n-j-1],prev[n-j]);
                }
            }
            prev=dp;
        }
        return n-dp[n];
    }
};