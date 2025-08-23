// Minimum days to make M bouquets


class Solution {
  public:
  bool isPossible(vector<int> &arr, int k , int m , int mid){
      int n = arr.size();
      int b = 0 ; 
      
      int i = 0 ; 
      int j = 0; 
      
      while(i < n &&  j < n ){
          if(arr[j] <= mid){
             
              if(j-i+1 == k ){
                  
                  b++;
                  if(b==m) return true; 
                  i = j+1 ; 
              }
          }
          else{
              i = j + 1; 
          }
          
          
          
          j++;
      }
     return b>=m; 
  }
  
  
    int minDaysBloom(vector<int>& arr, int k, int m) {
        // Code here
        int n = arr.size();
        
        if(n < 2*k) return -1; 
        
        int l = *min_element(arr.begin(), arr.end()) ; 
        int r = *max_element(arr.begin(), arr.end());
        
        int result = -1; 
        
        while(l<=r){
            int mid = l + (r- l )/2; 
            if(isPossible(arr, k , m , mid)){
              
                result = mid ;
                
                r = mid -1 ; 
            }
            else l = mid + 1;
        }
        return result; 
        
    }
};