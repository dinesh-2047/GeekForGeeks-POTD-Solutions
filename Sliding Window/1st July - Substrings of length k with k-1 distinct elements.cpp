// Substrings of length k with k-1 distinct elements


class Solution {
  public:
    int substrCount(string &s, int k) {
        
        int n = s.length();
        
        int i = 0 ; 
        int j = 0 ; 
        
        int result = 0; 
        
        unordered_map<char , int>mp; 
        
        while(j < n ){
             mp[s[j]]++;
            if(mp.size() == k - 1 && j- i + 1 == k){
                result++;
                mp[s[i]]--;
                if(mp[s[i]] == 0 ){
                    mp.erase(s[i]);
                }
                i++;
            }
            
            if(mp.size() >= k && j-i+1 == k ) {
                mp[s[i]]--;
                if(mp[s[i]] <= 0 ) mp.erase(s[i]);
                i++;
            }
            j++;
        }
        return result; 
    }
};