// Subarrays with sum K



class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        int n = arr.size();
        
        unordered_map<int , int>mp ; 
        
        mp[0]++;
         int sum = 0 ; 
         int count = 0; 
        for(int i = 0 ; i < n; i++){
             sum += arr[i];
             
             if(mp.count(sum-k)){
                 count+=mp[sum-k];
             }
             mp[sum]++;
        }
        return count; 
        
    }
};