// Generate Permutations of an array


// Approach 1 : Backtracking
class Solution {
  public:
  vector<vector<int>>result; 
  void solve(vector<int> &arr, int idx){
      if(idx >= arr.size()){
          result.push_back(arr);
          return ; 
      }
      
      for(int i = idx; i < arr.size(); i++){
          swap(arr[idx], arr[i]);
          solve(arr, idx + 1);
          swap(arr[idx], arr[i]);
      }
  }
  
    vector<vector<int>> permuteDist(vector<int>& arr) {
        solve(arr, 0);
      return result; 
    }
};



//Approach 2 : c++ STL
class Solution {
  public:
    vector<vector<int>> permuteDist(vector<int>& arr) {
      vector<vector<int>>result; 
      
      sort(begin(arr), end(arr));
      
       do{
           result.push_back(arr);
       }
       while(next_permutation(begin(arr), end(arr)));
       return result; 
    }
};