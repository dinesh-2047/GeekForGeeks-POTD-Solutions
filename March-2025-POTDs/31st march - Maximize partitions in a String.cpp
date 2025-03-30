// Maximize partitions in a String/


class Solution {
    public:
      int maxPartitions(string &s) {
         int n = s.length();
         
         unordered_map<char , int>last; 
         
         for(int i = 0 ; i<n; i++){
             last[s[i]] = i;
         }
         
         int ans = 0 ; 
         for(int i = 0 ; i<n; i++){
             int end = last[s[i]];
             for(int j = i ; j<end; j++){
                 if(last[s[j]] > end) end = last[s[j]];
             }
             ans++;
             i = end; 
         }
          return ans; 
      }
  };