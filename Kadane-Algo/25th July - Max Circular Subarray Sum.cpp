// Max Circular Subarray Sum

// Approach 1

class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        
        int n = arr.size();
        
        vector<int>maxSuffixSum(n+1, 0);
        int suffixSum = arr[n-1];
        
        maxSuffixSum[n-1] = arr[n-1];
        for(int i = n-2 ; i >= 0; i--){
            suffixSum += arr[i];
            maxSuffixSum[i] = max(maxSuffixSum[i+1], suffixSum);
        }
        
        int currSum = 0;
        int prefix = 0 ; 
        int circularSum = arr[0] ; 
        int maxSum = arr[0] ; 
        
        for(int i = 0 ; i < n; i++){
            currSum = max(arr[i], currSum  + arr[i]);
            maxSum = max(maxSum , currSum);
            
            prefix = prefix + arr[i];
            circularSum = max(circularSum , prefix + maxSuffixSum[i+1]);
        }
        return max(maxSum , circularSum);
        
    }
};







//Approach 2 
class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        int currMin =arr[0];
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