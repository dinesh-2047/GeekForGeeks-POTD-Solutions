// Count Numbers Containing Specific Digits



class Solution {
  public:
  long long findPower(int a , int b){
      if(b==0) return 1; 
      long long half = findPower(a, b/2);
      long long result = half * half ; 
      
      if(b%2==1){
          result = result * a;
      }
      return result; 
  }
  
    int countValid(int n, vector<int>& arr) {
        
       vector<bool>goodDigit(10, false);
       for(int a : arr){
           goodDigit[a] = true;
       }
       
       int f = 0 ; 
       int f0 = 0 ; 
       
       for(int i = 0 ; i  < 10;i++){
           if(!goodDigit[i]){
               f++;
               if(i!=0) f0++;
           }
       }
       
       int invalid = (n==1) ? f0 : f0 * findPower(f, n-1);
       
       int total = 9  * findPower(10, n-1);
       
       return total - invalid; 
    }
};
