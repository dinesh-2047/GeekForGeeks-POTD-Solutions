// Max sum subarray by removing at most one element

class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) {
       int n = arr.size();
       
       vector<int> left(n, 0), right(n , 0);
       
       left[0] = arr[0];
       right[n - 1] = arr[n - 1];
       
       int result = max(left[0], right[n - 1]);
       
       for(int i = 1; i < n; i++){
           left[i] = max(arr[i], arr[i] + left[i - 1]);
           result = max(result, left[i]);
       }
       
       for(int i = n- 2; i >= 0 ; i--){
           right[i] = max(arr[i], arr[i] + right[i  +1]);
           result = max(result, right[i]);
       }
       
       for(int i = 1; i  < n-1; i++){
           result = max(result, left[i - 1]+ right[i + 1]);
       }
       return result; 
        
    }
};