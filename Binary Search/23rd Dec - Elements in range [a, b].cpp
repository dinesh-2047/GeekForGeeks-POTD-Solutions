// Elements in range [a, b]

class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        sort(begin(arr), end(arr));
        int n = arr.size();
        
        vector<int>result;
        for(auto &q : queries){
            int a = q[0];
            int b = q[1];
            
            int lb = lower_bound(begin(arr), end(arr), a)-begin(arr);
            int ub = upper_bound(begin(arr), end(arr), b) -begin(arr);
            
            result.push_back(ub - lb);
        }
        return result; 
        
    }
};