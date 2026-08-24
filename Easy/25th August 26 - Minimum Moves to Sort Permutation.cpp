// Minimum Moves to Sort Permutation

class Solution {
  public:
    int minMoves(vector<int>& arr) {
        int n = arr.size();
        
        unordered_map<int , int > mp ; 
        
        int maxi = 0 ; 
        for(int i = 0 ; i < n; i++){
            mp[arr[i]] = mp[arr[i] - 1] + 1; 
            maxi = max(maxi, mp[arr[i]]);
        }
        return n - maxi ; 
    }
};