// Find all possible palindromic partitions of a String



class Solution {
  public:
  int n ; 
  bool isPalindrome( string &s){
      int n = s.length();
      int st = 0 ; 
      int end = n-1 ;  
      while(st <= end){
          if(s[st] != s[end]) return false; 
          st++;
          end--;
      }
      
      return true; 
  }
  
  void solve(int i , string &s, vector<vector<string>> &result , vector<string> &temp ){
      if(i >= n) {
          result.push_back(temp);
          return; 
      }
      
      string str = "";
      for(int j = i ;  j<n; j++){
          str += s[j];
          if(isPalindrome(str)){
              temp.push_back(str);
              solve(j+1,s, result , temp);
              temp.pop_back();
          }
      }
  }
  
    vector<vector<string>> palinParts(string &s) {
         n = s.length();
       vector<vector<string>>result; 
       
         vector<string> temp ; 
        solve(0, s, result , temp );
        return result; 
    }
};