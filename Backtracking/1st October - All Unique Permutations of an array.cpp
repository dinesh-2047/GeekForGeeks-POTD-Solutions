// All Unique Permutations of an array

// Approach 1 

class Solution {
  public:
  int n ; 
  
  void solve( vector<int> &arr, vector<int> curr, set<vector<int>> &st, vector<int>&visited){
      if(curr.size() == n ){
          st.insert(curr);
          return ; 
      }
      
      for(int i = 0 ; i < n; i++ ){
          if(!visited[i]){
              visited[i] = 1; 
          curr.push_back(arr[i]);
          solve(arr, curr, st, visited);
          visited[i] = 0; 
          curr.pop_back();
          }
      }
  }
  
    vector<vector<int>> uniquePerms(vector<int>& arr) {
         n = arr.size();
        sort(begin(arr), end(arr));
        vector<vector<int>>result; 
        vector<int>curr; 
        vector<int>visited(n , 0);
        set<vector<int>> st;
        solve(arr, curr, st , visited);
        
        for(auto &it : st ) result.push_back(it);
        
        return result; 
        
    }
};






//Approach 2 
class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        sort(begin(arr), end(arr));
        vector<vector<int>>result; 
        
        do{
            result.push_back(arr);
        }
        while(next_permutation(begin(arr), end(arr)));
        return result; 
        
    }
};