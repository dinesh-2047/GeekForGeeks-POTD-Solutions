// Maximum number of overlapping Intervals

class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        int n = arr.size();
        
        int maxi = 0;
        for(auto &interval :arr){
            maxi = max(maxi, interval[1]);
        }
        
        vector<int>vec(maxi+1, 0);
        for(auto &interval : arr){
            int st = interval[0];
            int end = interval[1];
            
            vec[st]++;
            if(end + 1 <= maxi) vec[end+1]--;
        }
        
        int result = vec[0] ; 
        for(int i = 1 ; i <= maxi; i++){
            vec[i] += vec[i-1];
            result = max(result, vec[i]);
        }
        return result; 
        
    }
};
