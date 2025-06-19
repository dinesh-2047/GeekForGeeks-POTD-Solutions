// Group Balls by Sequence


class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
      
      
       int n = arr.size();
       
       if(n%k!=0 || k > n ) return false; 
    
      map<int, int>mp ; 
       
        for(int i = 0 ;i <n; i++){
            mp[arr[i]]++;
        }
        
        for(auto &pair : mp){
            int num = pair.first; 
            int freq = pair.second; 
            
           if(freq > 0){
                for(int i = 0 ; i < k ; i++){
                    if(mp.find(num+i)==mp.end()) return false; 
                     mp[num+i]-=freq; 
                     if(mp[num+i]<=0) mp.erase(num+i);
                } 
            }
        }
        return true; 
    }
};