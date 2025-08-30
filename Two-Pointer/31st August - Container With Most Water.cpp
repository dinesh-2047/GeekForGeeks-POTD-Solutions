// Container With Most Water

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n =arr.size();
        int result = 0 ;
        int l = 0 ; 
        int r = n-1; 
        
        while(l < r){
            result = max(result , min(arr[l], arr[r])*(r-l));
            if(arr[l] >= arr[r]) r--;
            else l++;
        }
        return result; 
        
    }
};
