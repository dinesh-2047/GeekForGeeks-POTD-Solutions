// Bitonic Point


// Using cpp stl max element 
class Solution {
    public:
      int findMaximum(vector<int> &arr) {
          return *max_element(arr.begin(), arr.end());
          
      }
  };




// Using binary search 
class Solution {
    public:
      int findMaximum(vector<int> &arr) {
          int n = arr.size();
          
             int l = 0 ; 
             int r = n-1 ; 
             int result = 0 ; 
             
             while(l<=r){
                 int mid = l + (r- l)/2;
                 
                if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid + 1]) return arr[mid];
                if(arr[mid] < arr[mid + 1]) l = mid + 1; 
                else r = mid - 1; 
             }
             return 0 ; 
          
      }
  };