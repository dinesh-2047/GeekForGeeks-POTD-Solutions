// Rearrange the Array

class Solution {
  public:
  
  using ll = long long ;
  int mod = 1e9 + 7 ; 
  ll power(ll a, ll b ){
      if(b == 0 ) return 1; 
      ll half = power(a, b/2); 
      ll result = (half * half)%mod; 
      if(b%2 == 1){
          result = (result * a)%mod; 
      }
      return result; 
  }
    int minOperations(vector<int> &b) {
       int n = b.size();
       
       ll prev = 1; 
       vector<int> vis(n , false);
       vector<int> temp; 
       
       for(int i = 0 ;i < n; i++){
           if(vis[i]) continue; 
           ll curr = i ; 
           ll cnt = 0 ; 
           
           while(!vis[curr]){
               vis[curr] = 1; 
               curr = b[curr] - 1; 
               cnt++;
           }
           prev = ((prev * cnt) %mod * power(__gcd(prev, cnt), mod - 2)%mod)%mod;
       }
       return  prev%mod; 
    }
};