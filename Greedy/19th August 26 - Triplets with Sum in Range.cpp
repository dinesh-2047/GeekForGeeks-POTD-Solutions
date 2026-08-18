// Triplets with Sum in Range

class Solution {
  public:
  int n; 
  int solve(vector<int> &arr, int x){
      int count = 0 ; 
      
      for(int i = 0 ; i < n -2; i++){
          int left = i + 1; 
          int right = n - 1; 
          
          while(left < right){
              int sum = arr[i] + arr[left] + arr[right];
              
              if(sum <= x){
                  count += right -left; 
                  left++;
                  
              }
              else right--; 
          }
      }
      return count; 
  }
  int countTriplets(vector<int> &arr, int l, int r) {
        n = arr.size();
        sort(begin(arr), end(arr));
        
        return solve(arr, r) - solve(arr, l - 1);
        
    }
};