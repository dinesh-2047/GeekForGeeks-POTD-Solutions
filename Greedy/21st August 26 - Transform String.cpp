// Transform String

class Solution {
  public:
    int transform(string &s1, string &s2) {
        int n = s1.length();
        int m = s2.length();
        
        if(n != m ) return -1 ;
        
        unordered_map<char, int> mp ; 
        
        for(auto &ch : s1) mp[ch]++;
        
        for(auto &ch : s2){
            mp[ch]--;
            if(mp[ch] == 0) mp.erase(ch);
        }
        
        if(mp.size()) return -1 ; 
        
        int result = 0 ; 
        
        int i = n - 1; 
        int j = m - 1; 
        
        while(i >= 0 && j >= 0 ){
            if(s1[i] == s2[j]){
                i--;
                j--;
            }
            else {
                result++;
                i--;
            }
        }
        return result; 
    }
};
