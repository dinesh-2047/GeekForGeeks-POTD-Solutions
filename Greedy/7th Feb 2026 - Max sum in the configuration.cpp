// Max sum in the configuration

class Solution {
  public:
    int maxSum(vector<int> &arr) {
       int n = arr.size();
       
       int cumSum = 0 ;  
       int result = 0 ; 
       
       for(int i = 0 ; i  < n; i++){
           result += (i * arr[i]);
           cumSum += arr[i];
       }
       
       int curr = result; 
       
       for(int i = 1 ; i < n; i++){
           curr += cumSum - n * arr[n-i];
           result  = max(result, curr);
       }
       return result; 
       
    }
};