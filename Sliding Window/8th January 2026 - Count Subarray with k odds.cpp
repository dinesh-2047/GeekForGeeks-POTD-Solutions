// Count Subarray with k odds

class Solution {
  public:
  int atMost(vector<int> &arr, int k){
       int n  = arr.size();
       
       int oddCount = 0 ; 
       int result = 0  ;
       
       int i = 0 ; 
       int j = 0 ; 
       
       while( j < n ){
           if(arr[j]%2 == 1) oddCount++;
           
         while (oddCount > k) {
            if (arr[i] % 2 == 1) oddCount--;
            i++;
        }
           
           result += (j - i + 1);
           j++;
       }
       return result; 
  }
    int countSubarrays(vector<int>& arr, int k) {
      return atMost(arr, k) - atMost(arr, k - 1);
        
    }
};