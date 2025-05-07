// Missing element of AP



// First simple o(n) brute force 
class Solution {
    public:
      int findMissing(vector<int> &arr) {
          int n = arr.size();
          
          int diff = arr[1] - arr[0];
          
          for(int i = 1; i <n;i++){
              if(arr[i]!=arr[i-1] + diff) return arr[i-1]  +diff; 
          }
          return arr[n-1] + diff;
          
      }
  };



// second binary search 
class Solution {
    public:
      int findMissing(vector<int> &arr) {
          int n = arr.size();
          
          int diff = arr[1] - arr[0];
          
           int st = 0 ; 
           int end = n - 1; 
           
           
           while(st <= end){
               int mid = st + (end - st) /2;
               
               if(arr[mid+1] - arr[mid]!=diff) return arr[mid]  +diff; 
               
               else if(arr[mid] - arr[0] == mid *diff) {
                   st  = mid +1; 
                   
               }
               else end = mid - 1;
           }
           return arr[n-1] * diff; 
          
      }
  };