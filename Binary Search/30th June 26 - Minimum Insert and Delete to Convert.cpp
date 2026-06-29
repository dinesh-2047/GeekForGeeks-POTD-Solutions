// Minimum Insert and Delete to Convert

class Solution {
  public:
    int minInsAndDel(vector<int> &a, vector<int> &b) {
        int n = a.size();
        int m = b.size();
        
        
        unordered_map<int , int>mp ; 
        for(int i = 0  ; i  < m; i++){
            mp[b[i]] = i; 
        }
        
        
        vector<int> vec; 
        for(auto &x : a){
            if(mp.count(x)){
                vec.push_back(mp[x]);
            }
        }
        
        vector<int> lis; 
        for (int x : vec) {
                auto it = lower_bound(lis.begin(), lis.end(), x);
        
                if (it == lis.end())
                    lis.push_back(x);
                else
                    *it = x;
            }
            
            int l = lis.size();
            
            return (n - l ) + (m - l);
        
    }
};