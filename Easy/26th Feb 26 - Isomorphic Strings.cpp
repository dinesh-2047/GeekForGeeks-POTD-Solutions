// Isomorphic Strings

class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
       int n = s1.length();
       unordered_map<char, char>mp1 ; 
       unordered_map<char, char>mp2 ; 
       
       for(int i = 0 ; i  < n;i++){
          if(mp1.count(s1[i]) && mp1[s1[i]] != s2[i]) return false; 
          if(mp2.count(s2[i]) && mp2[s2[i]] != s1[i]) return false; 
          mp1[s1[i]] = s2[i];
          mp2[s2[i]] = s1[i];
       }
       
       return true; 
        
    }
};
