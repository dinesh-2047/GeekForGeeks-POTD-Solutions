// Longest Subarray Sum Divisible by K

class Solution {
  public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        
        int n = arr.size();
        
        unordered_map<int , int> mp ; 
        int sum = 0 ; 
        int result = 0 ; 
        
        mp[0] = -1; 
        
        for(int i = 0 ; i  < n; i++){
            sum += arr[i];
            int rem = ((sum%k)+k)%k; 
            if(mp.count(rem)){
                result = max(result, i - mp[rem]);
            }
            else mp[rem] = i; 
        }
        return result; 
    }
};