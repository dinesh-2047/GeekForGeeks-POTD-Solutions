// Equalize All Prefix Sums


class Solution {
  public:
    vector<int> optimalArray(vector<int> &arr) {
        int n = arr.size();
        
        vector<int> result;
        result.push_back(0);
        
        for(int i = 1 ; i  < n; i++){
            result.push_back(result.back() + (arr[i] - arr[i/2]));
        }
        return result;
        
    }
};