// Minimum Sum Subarray

class Solution {
  public:
    int minSubarraySum(vector<int> &arr) {
       int n = arr.size();
    
       int currMin = arr[0];
       int resultMin = arr[0];
       
       for(int i = 1; i < n; i++){
           currMin = min(currMin + arr[i], arr[i]);
           resultMin = min(resultMin, currMin);
       }
       return resultMin; 
    }
};