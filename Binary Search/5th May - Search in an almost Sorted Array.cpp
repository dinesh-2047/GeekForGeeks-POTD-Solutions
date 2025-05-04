// Search in an almost Sorted Array

class Solution {
    public:
      int findTarget(vector<int>& arr, int target) {
          int n = arr.size();
          
          
          int st = 0 ; 
          int end = n-1; 
          
          while(st <= end){
              int mid = st + (end - st)/2;
              
              if(arr[mid] == target) return mid ; 
              
            if(mid - 1 >= 0 && arr[mid - 1] == target) return mid - 1; 
          if(mid + 1 < n && arr[mid + 1] == target ) return mid +1;
              
              if(target > arr[mid]){
                  st = mid +1; 
              }
              else end = mid - 1; 
          }
          return -1 ; 
          
      }
  };