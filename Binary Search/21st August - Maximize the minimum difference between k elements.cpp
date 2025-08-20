// Maximize the minimum difference between k elements


class Solution {
  public:
  bool isPossible(vector<int> &arr , int mid, int k ){
      int n = arr.size();
      
      int c= 1 ; 
      int last = arr[0];
      for(int i = 1 ; i < n; i++){
          if(abs(arr[i] - last) >= mid){
              c++;
              last = arr[i];
          }
      }
      return c >= k ; 
  } 
  
  
    int maxMinDiff(vector<int>& arr, int k) {
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        
        int st = 0; 
        int end = abs(arr[0] - arr[n-1]);
        
        int result = 0 ; 
        while(st <= end){
            int mid = st + (end  -st )/2; 
            if(isPossible(arr, mid, k)){
                result = mid ; 
                st = mid + 1; 
            }
            else end = mid -1 ; 
        }
        return result; 
    }
};
