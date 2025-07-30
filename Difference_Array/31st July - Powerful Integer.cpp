// Powerful Integer

// tc-> O(nlogn)

class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        // code here
        int n = intervals.size();
        
        map<int , int>mp ; 
        
        
        for(auto &iv : intervals){
            mp[iv[0]]++;
            mp[iv[1]+1]--;
        }
        
        int result = -1 ; 
        int temp = 0 ; 
        for(auto &x : mp){
           
            if(mp[x.first] >=0 ){
                  temp += mp[x.first]; 
                  if(temp >= k ){
                      result = x.first; 
                  }
            }
            else{
                if(temp >= k){
                    result = x.first-1; 
                }
                temp += mp[x.first];
            }
        }
        return result; 
    }
};