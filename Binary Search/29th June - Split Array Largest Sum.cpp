// Split Array Largest Sum 

class Solution {
  public:
  
  bool isPossible(vector<int> &arr, int k , int mid ){
      int n = arr.size();
      int count =  1 ; 
      
      int sum =0 ; 
      for(int i = 0 ; i <n; i++){
          if(arr[i] > mid) return false; 
           sum += arr[i];
             if(sum  > mid){
              count++;
              sum = arr[i] ;
          }
         
         
      }
      return count <= k; 
  }
  
    int splitArray(vector<int>& arr, int k) {
       
       int n = arr.size();
     
       int cumSum = 0 ; 
       for(int i = 0 ; i <n; i++){
           cumSum += arr[i];
       }
        int result = -1 ; 
       
       int st = *max_element(begin(arr), end(arr)) ; 
       int end = cumSum ; 
       
       while(st<=end){
           int mid = st + (end  - st)/2;
           
           if(isPossible(arr, k , mid) ){
              result = mid ; 
               end  = mid - 1; 
           }
           else st = mid + 1;
       }
       
      return result; 
        
    }
};