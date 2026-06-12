// Binary Strings with Equal Sum of Two Halves


class Solution {
  public:
  using ll = long long ; 
  int mod = 1e9 + 7;
  
  ll power(ll a, ll b){
      if(b == 0 ) return 1;
      
      ll half = power(a, b/2);
      ll result = (half * half)%mod; 
      
      if(b%2 == 1){
          result = (result * a)%mod; 
      }
      return result %mod; 
  }
  
  
  ll flt(ll x, ll y){
      return (x *  power(y, mod - 2)%mod)%mod;
  }
    int computeValue(int n) {
        ll fact1 = 1; 
        for(int i = 1; i <= 2 * n ; i++){
            fact1 = (fact1 * i )%mod;
        }
        
        ll fact2 = 1; 
        for(int i= 1; i  <=  n; i++){
            fact2 = (fact2 * i )%mod; 
        }
        
        ll result = flt(fact1, fact2);
        result = flt(result, fact2);
        return(int) result; 
        
    }
};