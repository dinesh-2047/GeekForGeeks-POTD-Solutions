// Minimum Deletions to Make Sorted

class Solution {
  public:
    int minDeletions(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> lis; 
        lis.push_back(arr[0]);
        
        for(int i = 1 ; i  < n; i++){
            if(arr[i] > lis.back()){
                lis.push_back(arr[i]);
            }
            else {
                int idx = lower_bound(begin(lis), end(lis) , arr[i] ) - begin(lis);
                lis[idx] = arr[i];
            }
        }
        return n - lis.size();
    }
};