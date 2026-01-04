// Max Sum Subarray of size K


class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
      int n = arr.size();
      
      int i = 0 ; 
      int j = 0 ; 
      
      int sum = 0 ; 
      int result = 0 ;
      
      while(j < n ){
          sum += arr[j];
          
          if(j - i + 1 == k ){
              result = max(result , sum);
              sum -= arr[i];
              i++;
          }
          j++;
      }
      return result; 
        
    }
};