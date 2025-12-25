// Kth Missing Positive Number in a Sorted Array

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        int n = arr.size();
        
        int result = n;  
        
        int l = 0 ; 
        int r = n-1 ; 
        
        while(l <= r){
            int mid  = l + (r-l)/2; 
            
            if(arr[mid]-mid - 1 >=k ){
                result = mid ; 
                r = mid -1 ; 
            }
            else l = mid + 1; 
        }
        return result + k; 
        
        
    }
};