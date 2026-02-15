// Meeting Rooms

class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
       int n = arr.size();
       
       sort(begin(arr), end(arr));
       
      for(int i = 1; i < n; i++){
          int st = arr[i][0];
          if(st < arr[i-1][1]) return false; 
      }
      return true; 
        
    }
};