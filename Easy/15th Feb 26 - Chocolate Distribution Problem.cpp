// Chocolate Distribution Problem

class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        int n = a.size();
        
        sort(begin(a), end(a));
        
        int result = INT_MAX;
        for(int i = 0; i + m <= n ; i++){
            result = min(result , a[i+m-1] - a[i]);
        }
        return result; 
        
    }
};