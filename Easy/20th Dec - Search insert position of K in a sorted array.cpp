// Search insert position of K in a sorted array

class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
       return lower_bound(begin(arr), end(arr), k)-begin(arr);
        
    }
};