// Count Sorted Digit Groupings

class Solution {
    public:
int solve(string &s,int LeftSum,int idx,vector<vector<int>>&dp)
    {
        if(idx>=s.size())return 1;
        if(dp[idx][LeftSum]!=-1)return dp[idx][LeftSum];
        
        int sum = 0;
        int cnt = 0;
        
        for(int i=idx;i<s.size();i++){
            sum += int(s[i]-'0');
            if(sum>=LeftSum)
            {
                cnt+=solve(s,sum,i+1,dp);
            }
        }
        
        return dp[idx][LeftSum]=cnt;
    }
    int validGroups(string s){
        int sum=0;
        for(int i=0;i<s.size();i++)sum+=int(s[i]-'0');
        vector<vector<int>>dp(s.size() , vector<int>(sum+1 , -1));
        return solve(s,0,0,dp);
    }
};

