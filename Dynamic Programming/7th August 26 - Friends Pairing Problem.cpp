// Friends Pairing Problem


class Solution {
  public:
 vector<int> dp; 
  int solve(int n ){
       if(n <= 2) return n ; 
       if(dp[n]!=-1) return dp[n];
       return countFriendsPairings(n-1) + (n - 1) * countFriendsPairings(n-2);
  }
    int countFriendsPairings(int n) {
        dp.resize(n + 1, -1);
      return solve(n);
        
    }
};
