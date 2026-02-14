// The Painter's Partition Problem-II

class Solution {
  public:
  int n ; 
  bool isPossible(vector<int> &arr, int k , int mid ){
      int painters = 1 ;
      int sum = 0 ; 
      for(int i = 0 ; i < n; i++){
       
          if((sum + arr[i]) > mid){
              painters++;
              sum = arr[i];
          }
          else sum += arr[i];
          if(painters > k ) return false; 
      }
      return true; 
  }
    int minTime(vector<int>& arr, int k) {
    
       n = arr.size();
       
       int l = *max_element(begin(arr), end(arr)) ; 
       int r = accumulate(begin(arr), end(arr), 0);
       
       int result = 0 ; 
       
       while(l<=r){
           int mid = l + ( r - l)/2; 
           if(isPossible(arr, k , mid)){
               result = mid ; 
               r = mid -1 ; 
           }
           else l = mid + 1; 
       }
       return result; 
        
    }
};