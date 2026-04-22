// Two Equal Sum Subarray

class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        int n = arr.size();
        
        int total = accumulate(begin(arr), end(arr), 0);
        if(total%2 == 1) return false; 
        
        int sum = 0 ; 
        for(auto &x :arr){
            sum += x; 
            if(sum == total/2) return true; 
        }
        return false; 
    }
};
