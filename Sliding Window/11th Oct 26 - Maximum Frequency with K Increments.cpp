// Maximum Frequency with K Increments

class Solution {
  public:
    int maxFrequency(vector<int>& arr, int k) {
       int n = arr.size();
       
       sort(begin(arr), end(arr));
       
       long long sum = 0 ; 
       int i = 0 ; 
       int j = 0 ; 
       
       int result = 1; 
       
       while(j < n ){
           sum += arr[j];
           
           while(arr[j] * (j-i + 1) - sum > k ){
               sum -= arr[i];
               i++;
           }
           result = max(result, j - i + 1);
           j++;
       }
       return result;
        
    }
};