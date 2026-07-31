// Max After m Range Increments

class Solution {
  public:
  using ll = long long ; 
    int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k) {
        
        vector<ll> diff(n + 1 );
        
        for(int i =0 ;i  < a.size(); i++){
            diff[a[i]] += k[i];
            if(b[i] +  1 < n ){
                diff[b[i] + 1]-=k[i];
            }
        }
        
        ll result  =0 ; 
        ll curr = 0 ; 
        
        for(int i = 0 ;i  < n; i++){
            curr += diff[i];
            result = max(result, curr);
        }
        return result;
    }
};