// Minimum Cost to Merge Stones


class Solution {
  public:
 int dp[101][101];
    int solve(vector<int> &stones,int i,int j,vector<int> pre,int k){
        if(i>=j)return 0;
        int ans = INT_MAX;
        if(dp[i][j] != -1)return dp[i][j];
        for(int p = i;p < j;p = p+k-1){
            int val = solve(stones,i,p,pre,k)+solve(stones,p+1,j,pre,k);
            ans = min(ans,val);
        }
        if((j-i)%(k-1)==0){
            ans = ans + pre[j+1] - pre[i];
        }
        return dp[i][j] = ans;
    }
    int mergeStones(vector<int> &stones,  int k) {
        int n = stones.size();
        if((n-1)%(k-1) != 0)return -1;
        vector<int> pre(n+1,0);
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]+stones[i-1];
        }
        memset(dp,-1,sizeof(dp));
        return solve(stones,0,n-1,pre,k);
    }

};