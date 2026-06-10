// Equal Point in Brackets


class Solution {
  public:
    int findIndex(string &s) {
        int n = s.length();
        int totalClosing = 0 ; 
        for(auto &ch : s){
            if(ch == ')') totalClosing++;
        }
        if(totalClosing == 0 ) return 0 ; 
        int count_open = 0 ; 
        int count_close = 0 ; 
        
        
        
        for(int i = 0 ; i  < n; i++){
            if(s[i] == '(') count_open++;
            else count_close++;
            
            int rem_close = totalClosing - count_close; 
            if(count_open == rem_close) return i+1 ; 
        }
        return n; 
        
    }
};