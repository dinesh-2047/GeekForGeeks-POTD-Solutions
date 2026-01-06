// Count distinct elements in every window

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        vector<int>result; 
        int n = arr.size();
        
        unordered_map<int , int>mp ; 
        
        int i = 0; 
        int j = 0 ; 
        
        while( j < n ){
            mp[arr[j]]++;
            if(j - i + 1 == k ){
                result.push_back(mp.size());
                mp[arr[i]]--;
                if(mp[arr[i]] == 0 ) mp.erase(arr[i]);
                i++;
            }
            j++;
        }
        return result; 
        
    }
};
