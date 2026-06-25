// N-Digit Numbers with Increasing Digits

class Solution {
  public:
 vector<int> result; 
 
 void solve(int i , int digit  , int n , string s){
     if(digit == n){
         int val = stoi(s);
         result.push_back(val);
         return ; 
     }
     
     for(int j = i + 1; j  <= 9 ; j++){
         solve(j, digit + 1, n , s + to_string(j));
     }
     return ; 
     
 }
  
    vector<int> increasingNumbers(int n) {
       if(n > 9 ) return {};
       if(n == 1)
       result.push_back(0);
       
       solve(0, 0, n, "");
       
       return result; 
    }
};