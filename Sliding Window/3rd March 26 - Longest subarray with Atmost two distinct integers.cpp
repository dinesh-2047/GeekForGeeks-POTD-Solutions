// Longest subarray with Atmost two distinct integers

class Solution {
  public:
    int totalElements(vector<int> &arr) {
        
        int n = arr.size();
        
        unordered_map<int , int>mp; 
        
        int i  = 0 ; 
        int j = 0 ; 
        int result = 0 ;
        while(j < n ){
            mp[arr[j]]++;
            while(i <= j && mp.size() > 2){
                mp[arr[i]]--;
                if(mp[arr[i]] == 0 ){
                    mp.erase(arr[i]);
                }
                i++;
            }
            result = max(result, j - i + 1);
            j++;
            
        }
        return result;
        
    }
};