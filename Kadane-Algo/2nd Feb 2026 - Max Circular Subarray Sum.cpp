// Max Circular Subarray Sum

class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        int n = arr.size();
        
        int currMin = arr[0];
        int currMax = arr[0];
        int minSum = arr[0];
        int maxSum = arr[0];
        int cumSum = arr[0] ; 
        
        
        for(int i = 1 ; i  < n; i++){
             currMin = min(arr[i], currMin  + arr[i]);
             currMax = max(arr[i], currMax + arr[i]);
             
             minSum = min(minSum , currMin);
             maxSum = max(maxSum , currMax);
             
             cumSum +=arr[i];
        }
        if(minSum == cumSum) return maxSum ; 
        return max(maxSum , cumSum - minSum );
    }
};