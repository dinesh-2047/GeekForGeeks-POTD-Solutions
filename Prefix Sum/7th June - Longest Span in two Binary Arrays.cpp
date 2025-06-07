// Longest Span in two Binary Arrays



class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        int n = a1.size();
        
        int sum1 = 0 ; 
        int sum2 = 0 ; 
        int maxlen = 0 ; 
        unordered_map<int, int>mp ; 
        mp[0] = -1;
        for(int i = 0 ; i<n; i++){
            sum1 += a1[i];
            sum2 += a2[i];
            
            int diff = sum1 - sum2 ; 
            
            
            if(mp.find(diff)!=mp.end()){
                maxlen = max(maxlen , i - mp[diff]);
            }
            else mp[diff] = i ; 
        }
        return maxlen; 
    }
};