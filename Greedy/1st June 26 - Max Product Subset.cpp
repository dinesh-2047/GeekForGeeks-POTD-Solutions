// Max Product Subset


class Solution {
  public:
  int mod = 1e9 + 7; 
  using ll = long long ;
    int findMaxProduct(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return arr[0];
        int count0 = 0 ; 
        for(auto &x : arr) {
            if(x == 0 )  count0++;
        }
        if(count0 == n ) return 0 ; 
        ll result = 0; 
        bool have_zero = false; 
        for(int i = 0 ; i  < n; i++){
            if(arr[i] > 0 ) {
                if(result == 0 ) result = 1; 
                result =  (1LL * result * arr[i])%mod;
                
            }
            if(arr[i] == 0 ) have_zero = true; 
        }
        
        vector<int> neg; 
        for(int i = 0 ; i  < n; i++){
            if(arr[i] < 0) neg.push_back(arr[i]);
        }
        
        if(neg.size() <= 1 && neg.size() != n ) return result; 
        
        sort(begin(neg) ,end(neg));
        
        if(neg.size()%2 == 1){
            for(int i = 0 ; i  < neg.size() - 1; i++){
                if(result == 0 ) result = 1; 
                result = (1LL * result * neg[i])%mod;
            }
        }
        else {
            for(int i = 0 ; i  < neg.size(); i++){
                if(result == 0 ) result = 1; 
                result = (1LL * result * neg[i])%mod;
            }
        }
        
        
        return result; 
        
    }
};
