// Majority Element 

// Approach 1 
class Solution {
    public:
      int majorityElement(vector<int>& arr) {
         int n = arr.size();
         
         unordered_map<int , int>mp ; 
         for(auto &num : arr) mp[num]++;
         
         int ans = -1 ; 
         int count = 0 ; 
         
         
         for(auto &pair : mp){
             int num = pair.first; 
             int cnt = pair.second ; 
             
             if(cnt > n/2){
                 count++;
                 ans = num ;
             }
         }
          if(count > 1) return -1; 
          
          return ans; 
      }
  };



//Approach 2 
class Solution {
    public: // Boyer-Moore 
      int majorityElement(vector<int>& arr) {
         int n = arr.size();
         
         int count = 1; 
         int maj = arr[0];
         
         for(int i = 1; i < n; i++){
             if(count == 0 ){
                 maj = arr[i];
                 count = 1; 
             }
             else if(maj == arr[i]){
                 count++;
             }
             else count--;
         }
         //verification 
         count = 0 ; 
         for(int i = 0; i<n; i++){
             if(maj ==arr[i])count++;
         }
         if(count > n/2) return maj; 
         return -1; 
      }
  };