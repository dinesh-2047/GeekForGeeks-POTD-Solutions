// Max Sum Subarray of Size at least K


class Solution {
  public:
    int maxSumWithK(vector<int>& arr, int k) {
        int n = arr.size();
        
        int currSum = 0 ; 
        for(int i  = 0 ; i < k; i++) currSum += arr[i];
        
        int maxSum =currSum ; 
        int preMax = -1e9; 
        
        for(int i = k ; i  < n ; i++){
            currSum  += arr[i] - arr[i - k ];
            preMax = max({0, arr[i - k ], preMax + arr[i - k ]});
            maxSum = max(maxSum, currSum + preMax);
        }
        return maxSum; 
        
    }
};