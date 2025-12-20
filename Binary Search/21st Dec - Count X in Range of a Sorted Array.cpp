// Count X in Range of a Sorted Array

class Solution {
  public:
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int>result; 
        
        for(auto &q : queries){
            int l = q[0]; 
            int r = q[1];
            int x = q[2];
            
            int lb = lower_bound(begin(arr) + l , begin(arr) + r + 1, x) - begin(arr); 
            int ub = upper_bound(begin(arr) + l,begin(arr) + r + 1, x ) - begin(arr); 
            
            result.push_back(ub - lb );
        }
        return result; 
        
    }
};