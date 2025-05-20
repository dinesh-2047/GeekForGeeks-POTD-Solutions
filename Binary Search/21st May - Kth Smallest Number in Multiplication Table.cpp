// Kth Smallest Number in Multiplication Table



class Solution {
  public:
    int kthSmallest(int m, int n, int k) {
        int l= 1 ; 
        int r = m * n;
        
        int result = r; 
        
        while(l<=r){
            int mid = l + (r-l)/2;
            int count = 0  ; 
            for(int i = 1 ; i<= m ; i++){
                count += min(n , mid/i);
            }
            
            if(count >= k ){
                result = mid ; 
                r = mid - 1; 
            }
            else l = mid  +1; 
        }
        return result; 
        
    }
};