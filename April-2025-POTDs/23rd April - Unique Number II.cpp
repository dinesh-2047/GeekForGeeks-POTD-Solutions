// Unique Number II


// Approach 1 


class Solution {
    public:
      vector<int> singleNum(vector<int>& arr) {
          map<int , int>mp ;
          vector<int>ans; 
          int n = arr.size();
          for(int i = 0 ; i<n; i++){
              mp[arr[i]]++;
          }
          
          
          for(auto &pair : mp){
              int num = pair.first; 
              int cnt = pair.second; 
              
              if(cnt == 1) ans.push_back(num);
          }
          
          return ans; 
          
      }
  };