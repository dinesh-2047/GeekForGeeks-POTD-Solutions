// Roman Number to Integer

class Solution {
  public:
    int romanToDecimal(string &s) {
        int n = s.length();
        unordered_map<char , int>mp; 
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
         int result = 0 ; 
        for(int i = 0 ;i < n; i++){
            if(i-1>=0 && mp[s[i]] > mp[s[i-1]]){
               result +=  mp[s[i]] - 2*mp[s[i-1]]; 
            }
            else
            result += mp[s[i]];
        }
        return result; 
    }
};