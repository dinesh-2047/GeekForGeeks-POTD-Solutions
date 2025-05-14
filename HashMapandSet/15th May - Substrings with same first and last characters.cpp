// Substrings with same first and last characters



//Approach 1
class Solution {
  public:
    int countSubstring(string &s) {
        int n = s.length();
        
       vector<int>freq(26, 0);
       int result = 0 ; 
       for(char &ch : s) {
            freq[ch-'a']++;
            result += freq[ch-'a'];
       }
        
       return result ;
        
    }
}


// Approach 2
class Solution {
  public:
    int countSubstring(string &s) {
        int n = s.length();
        
       vector<int>freq(26, 0);
       int result = 0 ; 
       for(char &ch : s) {
            freq[ch-'a']++;
           
       }
       
       for(int i = 0 ; i<26; i++){
           int f = freq[i];
           
           result += (f * (f +1))/2;
       }
        
       return result ;
        
    }
};


