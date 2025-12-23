// Count elements less than or equal to k in a sorted rotated array 

class Solution {
    public:
    int countLessEqual(vector<int>& arr, int x) {
          int n = arr.size();
          
          int l = 0 ; 
          int r =n -1 ; 
          
          while(l < r){
              int mid = l + (r-l)/2; 
              if(arr[mid] > arr[r]){
                  l = mid + 1; 
              }
              else r = mid ; 
          }
          int pivot = l ; 
          
          int count = 0 ; 
          
          if(pivot > 0 ){
              count += upper_bound(begin(arr), arr.begin() + pivot , x)-begin(arr);
              
          }
          
          count += upper_bound(begin(arr) + pivot , end(arr), x) - (begin(arr) + pivot); 
     return count;    
    }
};
