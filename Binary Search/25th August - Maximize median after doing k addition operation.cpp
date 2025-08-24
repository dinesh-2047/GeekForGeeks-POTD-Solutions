// Maximize median after doing k addition operation


class Solution {
  public:
  bool isPossible(vector<int> &arr, int k , long long mid){
      int n = arr.size();
      
      if(n%2==1){
          int op = 0 ; 
          for(int i = n/2; i < n; i++){
              int r = mid - arr[i];
              if(r<=0){
                  continue; 
              }
              op += r; 
              
          }
          return op<=k; 
          
      }
      else{
           int op = 0 ; 
           if(arr[n/2] <= mid ){
               if(arr[n/2] < mid){
                    int r = mid - arr[n/2];
                    op+=r;
               }
               if(arr[n/2-1] < mid){
                   int r = mid - arr[n/2-1];
                   op+=r; 
               }
               
           }
           
           else{ // arr[n/2] > mid
               int r = (2*mid - (arr[n/2] + arr[n/2-1]));
               op+=r;
           }
           
           
           for(int i = n/2+1; i < n; i++){
               int r = mid - arr[i];
               if(r <= 0 ) continue; 
               else op+=r; 
               
           }
           return op <= k ; 
          
          
      }
  }
  
  
    int maximizeMedian(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int result = 0 ; 
        
        sort(arr.begin(), arr.end());
        long long l = 0 ; 
      if(n%2==0){
          l = (arr[n/2] + arr[n/2-1])/2;
      } 
      else l = arr[n/2];
      
      long long r = l + k ;
        
        while( l <= r){
            long long mid = l + (r-l)/2;
            if(isPossible(arr, k , mid)){
                result = mid ; 
                l = mid + 1;
            }
            else r = mid - 1; 
        }
        return result; 
    }
    
};