// Find Only Repetitive Element from 1 to n-1


// Approach 1 
class Solution {
    public:
      int findDuplicate(vector<int>& arr) {
          int n = arr.size();
          unordered_map<int , int>freq; 
          
          for(int i = 0 ; i<n; i++){
              freq[arr[i]]++;
          }
          
          for(auto &pair : freq){
              if(pair.second >1) return pair.first ;
          }
          return -1; 
          
      }
  };


// Approach 2 
class Solution {
    public:
      int findDuplicate(vector<int>& arr) {
          int n = arr.size();
          sort(arr.begin(), arr.end());
          
          for(int i = 0 ; i<n-1; i++){
              if(arr[i] == arr[i + 1]  ) return arr[i];
          }
          return -1;
          
      }
  };


// Approach 3 
class Solution {
    public:
      int findDuplicate(vector<int>& arr) {
           int n = arr.size();
           
           unordered_set<int>st(arr.begin(),arr.end());
           
           int setSum = 0 ; 
           for(auto &s : st){
               setSum +=s;
           }
           int cumSum = 0 ; 
           for(auto &num: arr){
               cumSum +=num; 
           }
           
           return cumSum- setSum ;
          
      }
  };