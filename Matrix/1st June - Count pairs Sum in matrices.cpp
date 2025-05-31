// Count pairs Sum in matrices


class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
    
      int n =  mat1.size();
       unordered_map<int , int>mp ; 
       
       for(auto &v : mat2) {
           for(auto &num : v) mp[num]++;
       }
       int count = 0 ; 
       
      for(int i = 0 ;i<n; i++){
          for(int j = 0 ; j < n; j++){
              int num = mat1[i][j];
              
              int target = x - num; 
              
              if(mp.find(target)!=mp.end()) count++;
          }
      }
      return count; 
        
    }
};