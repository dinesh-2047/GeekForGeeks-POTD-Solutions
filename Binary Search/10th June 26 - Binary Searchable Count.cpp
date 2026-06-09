// Binary Searchable Count


class Solution {
  public:
    int binarySearchable(vector<int>& arr) {
        int n = arr.size();
        
         int result = 0 ; 
        for(int i = 0 ; i < n; i++){
            int target = arr[i];
            
            int l = 0 ; 
            int r = n - 1; 
            
            while(l <= r){
                int mid = l + ( r - l )/2; 
                if(arr[mid] == target){
                    result++;
                    break; 
                }
               else  if(arr[mid] > target) r = mid - 1; 
                else{
                    l = mid + 1; 
                }
            }
        }
        return result; 
        
    }
};