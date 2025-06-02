// Substrings with K Distinct


class Solution {
  public:
  int solve(string &s, int k ){
      int n = s.length();
       
       int i = 0 ; 
       int j = 0 ; 
       unordered_map<char , int>mp ; 
       int result = 0 ; 
       
       while(j < n ){
           mp[s[j]]++;
           
           while( mp.size() > k){
               
               
               mp[s[i]]--;
               if(mp[s[i]]==0){
                   mp.erase(s[i]);
               }
               i++;
           }
           result+=(j-i+1);
           j++;
       }
       return result; 
  }
  
    int countSubstr(string& s, int k) {
       return solve(s, k ) - solve(s,k-1);
    }
};