// Count Subarrays with given XOR

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
       
        int n = arr.size();
        
        long result = 0 ; 
        unordered_map<int , int>mp; 
        
        int xorr = 0 ;
        for(int i = 0 ; i  < n; i++){
            xorr ^= arr[i];
            if(xorr == k ) result++;
            if(mp.count(xorr^k)){
                result += mp[xorr^k];
            }
 
                mp[xorr]++;
            
            
        }
        return result;
    }
};