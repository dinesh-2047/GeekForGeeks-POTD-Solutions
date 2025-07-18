// Count Unique Vowel Strings

class Solution {
  public:
  
  
  
  bool isVowel(char ch ){
      return (ch =='a' || ch =='e' || ch=='i' || ch=='o' || ch =='u');
  }
  
  
  int fact(int n ){
      int result = 1 ; 
      for(int i = 1 ;i <= n; i++){
          result *= i; 
      }
      return result; 
  }
  
    int vowelCount(string& s) {
        
        int n = s.length();
        
        unordered_map<char , int>mp ; 
        for(auto &ch : s){
            if(isVowel(ch))
            mp[ch]++;
        }
        
        if(!mp.size() ) return 0; 
    
        int result = 1;         
                      
        for(auto &pair : mp){
            char ch = pair.first ; 
            int freq = pair.second ; 
            result *= freq; 
        } 
        return result *fact(mp.size()) ; 
        
    }
};