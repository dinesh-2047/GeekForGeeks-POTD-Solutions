// Minimum Increment or Double Operations to Convert


class Solution {
  public:
    int countMinOperations(vector<int>& arr) {
       int n = arr.size();
       int result = 0 ; 
       int maxi = *max_element(begin(arr),end(arr));
       
       for(int i = 0 ; i  < n; i++){
           result += (__builtin_popcount(arr[i]));
       }
       return result  + log2(maxi); 
        
    }
};