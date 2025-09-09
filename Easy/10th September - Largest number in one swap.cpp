// Largest number in one swap


class Solution {
  public:
    string largestSwap(string &s) {
        int n = s.length();
        
        int maxRight = INT_MIN;
        for(int i = 1; i < n ; i++){
            if(maxRight == INT_MIN) maxRight = i ; 
            else if(s[maxRight] <= s[i]) maxRight = i; 
        }
        
        for(int i = 0 ; i <maxRight ; i++  ){
            if(s[i] < s[maxRight]){ 
                swap(s[i], s[maxRight]);
                return s; 
            }
        }
        
        return s; 
        
    }
};