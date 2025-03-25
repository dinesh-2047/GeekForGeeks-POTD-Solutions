// Word Break


class Solution {
    public:
    int n ; 
   
    int solve(string &s, vector<string> &dictionary , int i,set<string>&st , vector<int>&dp){
        if(i==n) return 1; 
        
  
        if(dp[i]!=-1) return dp[i];
        
        string temp = "";
        for(int l = i ; l <n; l++){
             temp +=s[l];
            if(st.find(temp)!=st.end() && solve(s, dictionary , l + 1,st,dp)) return dp[i]= 1;
        }
        return dp[i] =  0; 
    }
      int wordBreak(string &s, vector<string> &dictionary) {
          n = s.length();
      set<string>st;
          for(int i = 0 ; i<dictionary.size();i++ ){
              st.insert(dictionary[i]);
          }
          vector<int>dp(n+1, -1);
          return solve(s, dictionary , 0,st, dp);
          
      }
  };
  