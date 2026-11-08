// Count Group Occurrences

class Solution {
  public:
    int getCount(string &s, int k) {
        int n = s.length();
        
        int result = 0 ; 
        for(char ch = 'a'; ch <= 'z'; ch++){
            int groups = 0 ; 
            int count = 0 ; 
            for(int i = 0 ; i  < n; i++){
                if(s[i] == ch){
                    if(count == 0 ) groups++;
                    count++;
                }
                else count = 0;
            }
            if(groups == k) result++;
        }
        return result; 
        
    }
};