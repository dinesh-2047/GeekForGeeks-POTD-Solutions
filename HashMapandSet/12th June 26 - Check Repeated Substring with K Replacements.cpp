// Check Repeated Substring with K Replacements


class Solution {
  public:
    bool kSubstr(string &s, int k) {
        int n = s.length();
        
        if(n%k != 0 ) return 0 ; 
        
        unordered_map<string, int> mp ; 
        for(int i= 0 ; i  < n; i+=k){
            string str = s.substr(i, k);
            mp[str]++;
        }
        
        
        if(mp.size() == 1) return true; 
        if(mp.size()!=2 )return false; 
        if(mp.begin()->second == n/k-1 || mp.begin()->second == 1) return true; 
        return false; 
    }
};