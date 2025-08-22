// Allocate Minimum Pages


class Solution {
  public:
  bool isPossible(vector<int>&arr, int k , int mid){
     int n = arr.size();
     
     int sum = 0; 
     int s =1 ; 
     for(int i = 0 ; i < n; i++){
     
         if(sum + arr[i] <= mid){
             sum += arr[i];
         }
         else {
             s++;
             sum = arr[i];
         }
     }
     
    if(s > k  ) return false; 
    else return true; 
  }
  
    int findPages(vector<int> &arr, int k) {
        
        int n = arr.size();
        if( k > n ) return -1; 
        
        
        int l = *max_element(begin(arr), end(arr)) ; 
        int r = accumulate(arr.begin(), arr.end(), 0);
         int result = 0 ; 
        while(l <= r){
            int mid =  l + (r- l )/2;
            if(isPossible(arr, k , mid)){
                result = mid; 
             
                r = mid - 1; 
            }
            else l = mid + 1; 
        }
        return result; 
    }
};