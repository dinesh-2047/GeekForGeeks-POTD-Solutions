// Minimum Time with 2 Scanners


class Solution {
  public:
    int minTime(int n, int s1, int s2) {
        int result = 0 ; 
        
        int l = 0 ; 
        int r = n * min(s1, s2);
        
        
        while(l <= r){
            int mid = l + (r - l )/2; 
            
            if(mid/s1 + mid/s2 >= n ){
                result = mid ; 
                 r = mid - 1; 
            }
            else l = mid + 1; 
        }
        return result;
        
    }
};