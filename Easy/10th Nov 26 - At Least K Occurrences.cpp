// At Least K Occurrences

class Solution {
  public:
    int firstElementKTime(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int , int> freq; 
        unordered_map<int , int> xk; 
        
        
        for(int i = 0 ;i < n; i++){
            freq[arr[i]]++;
            if(freq[arr[i]] == k){
                xk[arr[i]] = i; 
            }
        }
        
        int result = -1; 
        int last = n ; 
        
        for(auto [x, cnt] : freq){
            if(cnt >= k ){
                 if( xk[x] < last){
                     result = x; 
                     last = xk[x];
                 }
            }
        }
        return result; 
    }
};