// Missing Element in Range

class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        unordered_set<int>st(begin(arr), end(arr));
        vector<int>result; 
        
        for(int i = low; i <= high; i++){
            if(!st.count(i)) result.push_back(i);
        }
        return result; 
        
    }
};