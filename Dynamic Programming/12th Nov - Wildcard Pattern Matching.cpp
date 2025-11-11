// Wildcard Pattern Matching

class Solution {
  private:    
    bool solve(int i,int j,string &pat,string &txt,vector<vector<int>> &dp){
        //base case
        
        if(i==0 && j==0){
            return true;
        }
        if(i==0 && j>0){
            return false;
        }
        if(j==0 && i>0){
            for(int ind=1; ind<=i; ind++){
                if(pat[ind-1] != '*'){
                    return false;
                }
            }
            
            return true;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(pat[i-1]==txt[j - 1] || pat[i-1]=='?'){
            return dp[i][j] = solve(i-1,j-1,pat,txt,dp);
        } 
        else if(pat[i-1]=='*'){
            return dp[i][j] =solve(i,j-1,pat,txt,dp) || solve(i-1,j,pat,txt,dp) || solve(i-1,j-1,pat,txt,dp);
        } 
        else{
            return dp[i][j]=false;
        }
    }     
  public:
    bool wildCard(string &txt, string &pat) {
       // code here
     
        int n=pat.size();
        int m=txt.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1,-1));
        return solve(n,m,pat,txt,dp);
    }
};