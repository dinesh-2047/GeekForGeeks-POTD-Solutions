// Sum of Pairwise ANDs

class Solution {
  public:
  using ll = long long ; 
    long long pairAndSum(vector<int> &arr) {
        int n = arr.size();
        
        ll result = 0 ; 
        for(int mask = 0 ; mask < 32; mask++){
            ll cnt = 0 ; 
            for(auto &x : arr){
                cnt += (x >>mask)&1;
            }
            if(cnt > 1){
                result += (1 << mask) * (cnt * (cnt - 1))/2; 
            }
        }
        return result;
    }
};