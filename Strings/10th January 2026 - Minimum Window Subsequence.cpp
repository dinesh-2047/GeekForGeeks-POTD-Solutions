// Minimum Window Subsequence.

class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        int n = s1.length();
        int m = s2.length();
        
        int i = 0 ; 
        int j = 0 ; 
        
        int minLen = INT_MAX; 
        int st = 0 ; 
        
        while(i < n ){
            if(s1[i] == s2[j]) j++;
            
            if(j == m ){
                int end = i ; 
                
                j--;
                
                while( j >= 0 ){
                    if(s1[i] == s2[j]) j--;
                    i--;
                }
                i++;
                j++;
                
                int currLen = end - i + 1;
                
                if(currLen < minLen) {
                    minLen = currLen ; 
                    st = i ; 
                }
            }
            i++;
        }
        
        return minLen == INT_MAX ? "" : s1.substr(st, minLen);
        
    }
};
