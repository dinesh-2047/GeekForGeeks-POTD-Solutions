// Number of BST From Array


class Solution {
  public:
  using ll = long long ; 
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        
        vector<int>result; 
        
        vector<ll>cat(n + 1, 0);
        
        cat[0] = 1;
        cat[1] = 1;
        
        vector<int>vec  = arr; 
        
        sort(begin(vec), end(vec));
        
        for(int i = 2; i <= n ; i++){
            for(int j = 0 ; j < i ; j++){
                cat[i] +=(cat[j] * cat[i - j - 1]);
            }
        }
        
        for(int i = 0; i  < n; i++){
            int idx = lower_bound(begin(vec),end(vec), arr[i]) - begin(vec);
            int left = idx ; 
            int right = n - idx - 1; 
            
            result.push_back((int)cat[left] * cat[right]);
        }
        return result; 
        
    }
};