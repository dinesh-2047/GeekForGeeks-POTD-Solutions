// Wifi Range


class Solution {
  public:
    bool wifiRange(string &s, int x) {
        int n = s.length();
        
        int count0 = 0 ; 
        
        for(auto &ch : s){
            if(ch == '0') count0++;
            else {
                if(count0 > x) return false; 
                count0 = -x; 
            }
        }
        if(count0 > 0) return false; 
        return true; 
        
    }
};