// Smallest distinct window

class Solution {
    public:
      int findSubString(string& str) {
         
         unordered_set<char>st(str.begin(), str.end());
         int k = st.size();
         
         int n = str.length();
         
         int result = INT_MAX ; 
         int i = 0 ; 
         int j = 0 ; 
         unordered_map<char , int>mp ; 
         
         while(j < n){
             mp[str[j]]++;
             
             while(i<=j && mp.size() == k){
                 result =  min(result,j-i+1);
                 mp[str[i]]--;
                 if(mp[str[i]] == 0){
                     mp.erase(str[i]);
                 }
                 i++;
             }
             j++;
         }
         return result; 
      }
  };