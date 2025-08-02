Longest Subarray with Majority Greater than K
// 

class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
         
         int n = arr.size();
         
         unordered_map<int , int>mp ; 
         
         int result = 0 ; 
         int sum = 0 ; 
         
         for(int i = 0 ;i < n; i++){
             
             if(arr[i]  > k ) sum += 1;
             else sum -=1;
             
             if(sum > 0 ){
                 result = i + 1; 
             }
             else{
                 if(mp.count(sum - 1)){
                     result = max(result , i - mp[sum-1]);
                 }
             }
             if(!mp.count(sum))
                mp[sum] = i ;
         }
         return result; 
    }
};