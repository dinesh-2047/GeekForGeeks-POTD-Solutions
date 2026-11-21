// Smallest Subarray Sum Greater Than x

class Solution {
  public:
    int smallestSubWithSum(vector<int>& arr, int x) {
        int n = arr.size();
        
        int i = 0 ; 
        int j = 0 ; 
        int result = 1e9 ; 
        int sum = 0 ; 
        while(j < n){
            sum += arr[j];
            while(i<=j&&sum > x){
                result = min(result, j-i + 1);
                sum -= arr[i];
                i++;
            }
            j++;
        }
        return result == 1e9 ? 0 : result; 
        
    }
};