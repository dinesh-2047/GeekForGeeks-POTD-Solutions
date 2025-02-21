// Longest valid Parentheses



// Approach 1
class Solution {
    public:
      int maxLength(string& s) {
          int n = s.length();
          
          int count = 0 ; 
          int ans = 0 ; 
          stack<int>st; 
          st.push(-1);
          for(int i = 0 ; i<n; i++){
              if(s[i]=='(') st.push(i);
              
              else{
                  st.pop();
                  if(!st.empty()){
                      ans = max(ans, i - st.top());
                 } else st.push(i);
              
          }
          }
          return ans; 
      }
  };


// Approach 2 
class Solution {
    public:
      int maxLength(string& s) {
         int n = s.length();
         int open = 0 ; 
         int close = 0 ; 
         int maxlen = 0 ; 
         
         for(int i = 0 ; i<n; i++){
             if(s[i]=='(') open++;
            
             else if(s[i]==')') close++;
             
             if(open == close) {
                 maxlen = max(maxlen , open + close);
             }
             else if (close > open ) open = close = 0 ; 
         }
         
         open = 0 ; 
         close = 0 ; 
         
         for(int i = n - 1; i >= 0; i--){
             if(s[i]=='(') open++;
             else if(s[i] == ')') close++;
             
             if(open == close) maxlen = max(maxlen,close + open);
             else if(open > close) open = close = 0 ; 
         }
         return maxlen ;
      }