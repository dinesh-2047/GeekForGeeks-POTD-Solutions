// Exactly one swap


class Solution {
  public:
    int countStrings(string &s) {
       int n = s.length();
       vector<int>freq(26,0);
       for(int i = 0 ; i <n; i++){
           freq[s[i]-'a']++;
       }
       int repeating = 0; 
       for(int i = 0 ; i <26; i++){
           repeating = repeating + ((freq[i])*(freq[i]-1))/2;
       }
       
       int result = (n *(n-1))/2;
       result -= repeating ; 
       
       if(repeating!=0) result +=1;
       
       return result; 
    }
};