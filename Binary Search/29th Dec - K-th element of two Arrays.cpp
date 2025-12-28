// K-th element of two Arrays


class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        if(a.size() > b.size()){
            return kthElement(b, a, k);
        }
        
        int m = a.size();
        int n = b.size();
        
        int l =max(0, k-n) ; 
        int r = min(k , m); 
        
        while( l<=r){
            int px = l + (r-l)/2;
            int py = k - px; 
            
            int x1 = (px == 0 ) ? INT_MIN : a[px - 1];
            int x2 = (py == 0 ) ? INT_MIN : b[py - 1];
            
            int x3 = (px == m)  ? INT_MAX : a[px];
            int x4 = (py == n ) ? INT_MAX : b[py];
            
            if(x1 <= x4 && x2 <= x3){
                return max(x1, x2);
            }
            else if(x1 > x4){
                r = px - 1; 
            }
            else l = px + 1; 
        }
        return 0;
    }
};