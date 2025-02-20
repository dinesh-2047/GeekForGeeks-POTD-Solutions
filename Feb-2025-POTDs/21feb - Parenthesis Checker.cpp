// Parenthesis Checker


// Approach using stack 
class Solution {
    public:
      bool isBalanced(string& s) {
          int n = s.length();
          
          if(n%2==1) return false; 
          
          stack<int>st; 
          for(int i =0; i<n; i++){
              if(s[i]=='{' || s[i] == '(' || s[i] == '['){
                  st.push(s[i]);
              }
              
              else if(st.empty()) return false; 
              
              else {
                  if(s[i]==')') {
                      if(st.top()!='(') return false;
                  }
                  
                  if(s[i]=='}'){
                      if(st.top()!='{') return false; 
                  }
                  if(s[i]==']') {
                       if(st.top()!='[') return false; 
                  }
                  st.pop();
              }
              
              
          }
          if(st.empty()) return true; 
          else return false; 
      }
  };