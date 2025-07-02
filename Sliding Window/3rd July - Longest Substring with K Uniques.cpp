// Longest Substring with K Uniques



class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        
        
        int n = s.length();
        
        unordered_map<char , int>mp ; 
        
        int i = 0; 
        int j  = 0 ; 
        
        int result = -1 ; 
        
        
        while(j < n ){
          mp[s[j]]++;
          
          if(mp.size() > k ){
              mp[s[i]]--;
              if(mp[s[i]] == 0 ){
                  mp.erase(s[i]);
              }
              i++;
          }
          if(mp.size() == k )
          result = max(result , j - i + 1 );
          
          j++;
        }
        return result; 
        
    }
};