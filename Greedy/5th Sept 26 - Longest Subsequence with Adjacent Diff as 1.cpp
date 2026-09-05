// Longest Subsequence with Adjacent Diff as 1
class Solution {
  public:
    int longestSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp ; 
        int result = 1 ; 
        
        for(int i = 0 ; i < n; i++){
            int curr = 1; 
            if(mp.count(arr[i] + 1)){
                curr = max(curr, mp[arr[i] + 1] + 1);
            }
            if(mp.count(arr[i] - 1)){
                curr = max(curr, mp[arr[i] - 1]+1);
            }
            
            mp[arr[i]] = max(mp[arr[i]], curr);
            result = max(result, curr);
            
            
        }
        return result; 
        
    }
};