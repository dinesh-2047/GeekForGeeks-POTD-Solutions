// Sort 0s, 1s and 2s

class Solution {
  public:
    void sort012(vector<int>& arr) {
      int n = arr.size();
      
      int l = 0 ;
      int m = 0 ; 
      int r = n-1; 
      
      
      while(m<=r){
          if(arr[m] == 2 ){
              swap(arr[m], arr[r]);
              r--;
              
          }
          else if(arr[m] == 0){
              swap(arr[m], arr[l]);
              l++;
              m++;
          }
          else{
              m++;
          }
      }
        
        
    }
};