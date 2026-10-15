// Successful Binary Searches Irrespective of Pivot

class Solution {
  public:
    int countAlwaysFound(vector<int>& arr) {
         int n = arr.size();
         
         vector<int> lmax(n);
         lmax[0] = arr[0];
         for(int i = 1; i  < n; i++){
             lmax[i] = max(lmax[i - 1], arr[i]);
         }
         int rmin = arr[n-1];
         
         int result = 0 ; 
         if(arr[n-1] == lmax[n-1]) result++;
         
         for(int i = n - 2; i  >= 0 ; i--){
             if(arr[i] == lmax[i] && arr[i] < rmin){
                 result++;
             }
                 rmin = min(rmin, arr[i]);
             
         }
         return result;
    }
};