// Unique NUmber III  

class Solution {
    public:
      int getSingle(vector<int> &arr) {
          unordered_map<int , int>mp;
          
          for(auto &num : arr){
              mp[num]++;
              
          }
          
          for(auto &pair : mp){
              int num = pair.first; 
              int cnt = pair.second; 
              
              if(cnt == 1) return num ;
              }
              return -1;
          
      }
  };