// Maximum Product Subarray


class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        int n  = arr.size();
        
       int pref = 1 ; 
       int suff = 1 ; 
       int result = INT_MIN; 
       
       for(int i = 0 ; i  < n; i++){
           if(arr[i] == 0 ){
               pref  = 1; 
               result = max(result , 0);
           }
           else{
               pref *= arr[i];
               result = max(result , pref);
           } 
           
           
       }
       
       for(int i = n-1 ; i >= 0; i--){
            if(arr[i] == 0 ){
               suff  = 1; 
                 result = max(result , 0);
           }
           else{
                suff *= arr[i];
                  result = max(result , suff);
           }
           
         
       }
       return result; 
    }
};