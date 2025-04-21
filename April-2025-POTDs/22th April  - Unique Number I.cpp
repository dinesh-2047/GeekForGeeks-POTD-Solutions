// Unique Number I 


// Approach 1  
class Solution {
    public:
      int findUnique(vector<int> &arr) {
         int n = arr.size();
         int ans = 0 ; 
         
         for(int i = 0 ; i < n; i++){
             ans ^= arr[i];
         }
         return ans ;
          
      }
  };



//Approach 2 
class Solution {
    public:
      int findUnique(vector<int> &arr) {
         unordered_map<int, int >mp ; 
         for(auto &a :arr) mp[a]++;
         
         for(auto &pair : mp){
             int num = pair.first; 
             int cnt = pair.second; 
             
             if(cnt ==  1) return num ;
         }
         return -1; 
          
      }
  };