// Overlapping Intervals

class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        vector<vector<int>> result;
        result.push_back(arr[0]);
        for(int i = 1;i<n ;i++)
        {
            vector<int> x = result.back();
            result.pop_back();
            if(x[1]>= arr[i][0])
            {
                result.push_back({x[0],max(arr[i][1],x[1])});
            }
            else
            {
                result.push_back(x);
                result.push_back(arr[i]);
            }
        }
        return result;
    }
};