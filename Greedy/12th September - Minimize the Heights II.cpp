// Minimize the Heights II





class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
       int n = arr.size();
       
       sort(begin(arr), end(arr));
       
       int diff = arr[n-1] - arr[0];
       
       for(int i = 1;i  < n; i++){
           if(arr[i] - k < 0 ) continue;  
           int minH = min(arr[0] + k , arr[i] - k );
           int maxH = max(arr[i-1] + k , arr[n-1] - k );
           diff = min(diff , maxH - minH);
       }
       return diff; 
        
    }
};