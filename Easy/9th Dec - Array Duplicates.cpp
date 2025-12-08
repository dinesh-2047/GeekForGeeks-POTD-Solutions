// Array Duplicates

class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        int n = arr.size();
      vector<int>result; 
      
      for(int i = 0 ; i < n ;i++){
          int idx = abs(arr[i]) - 1; 
          if(arr[idx] > 0 ){
              arr[idx] = -1 * arr[idx];
          }
          else result.push_back(abs(arr[i]));
      }
      return result; 
    }
};