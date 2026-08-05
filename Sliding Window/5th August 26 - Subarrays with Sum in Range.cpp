// Subarrays with Sum in Range


class Solution {
  public:
  int n ; 
  int solve(vector<int> &arr, int k){
      int result = 0 ; 
      int sum = 0 ; 
      int i = 0 ; 
      int j = 0 ; 
      
      while(j < n){
          sum += arr[j];
          while(i <= j && sum > k ){
              sum -= arr[i];
              i++;
          }
          j++;
          result += ( j - i + 1);
      }
      return result; 
  }
    int countSubarray(vector<int>& arr, int l, int r) {
        n = arr.size();
        
        return solve(arr, r) - solve(arr, l - 1);
        
    }
};