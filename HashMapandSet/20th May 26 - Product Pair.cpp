// Product Pair/

class Solution {
  public:
    bool isProduct(vector<int>& arr, long long target) {
        int n = arr.size();
        
        unordered_map<int , int> mp; 
        for(int i= 0 ; i  < n; i++){
            mp[arr[i]]++;
        }
        
        for(int i = 0 ; i  < n; i++){
            int x = target/arr[i];
            if(mp.count(x)){
                if((1LL * x * arr[i]) == target){
                    if(x == arr[i] && mp[x] > 1)
                    return true; 
                    if(x!=arr[i]) return true; 
                }
            }
        }
        return false;
    }
};