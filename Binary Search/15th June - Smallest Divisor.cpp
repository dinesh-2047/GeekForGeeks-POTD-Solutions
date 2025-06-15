// Smallest Divisor


class Solution {
  public:
  
  bool isPossible(vector<int> &arr, int k, int mid ){
      int n = arr.size();
      
      int ceilSum = 0 ; 
      
      for(int i = 0 ; i <n; i++){
          ceilSum = ceilSum + ceil((double)arr[i]/mid);
      }
      
      return ceilSum <=k;
  }
  
    int smallestDivisor(vector<int>& arr, int k) {
        int n = arr.size();
        
       
       
       int st = 1; 
       int end = *max_element(arr.begin() ,arr.end()) + k; 
       int result = end; 
       
       while(st <= end){
           int mid = st + (end -st)/2;
           
           if(isPossible(arr, k, mid)){
               result = mid;
               end = mid - 1;
           }
           else st = mid + 1; 
       }
       
       return result; 
        
    }
};
