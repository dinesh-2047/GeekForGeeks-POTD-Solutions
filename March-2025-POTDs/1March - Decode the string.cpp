// Decode the string 

class Solution {
    public:
      string decodedString(string &s) {
        
        stack<int> num; 
          stack<string> st;  
          string curr = "";  
          int n = s.length();
          int number = 0;
  
          for(int i = 0; i < n; i++) {
              if(isdigit(s[i])) {  
                  number = number * 10 + (s[i] - '0'); // Handle multi-digit numbers
              }
              else if(s[i] == '[') {
                  num.push(number); 
                  number = 0;  // Reset number after pushing
                  st.push(curr); 
                  curr = ""; // Reset curr for inner sequence
              }
              else if(isalpha(s[i])) {
                  curr += s[i]; 
              }
              else if(s[i] == ']') {
                  int repeat = num.top(); num.pop();
                  string temp = curr;
                  curr = st.top(); st.pop();
                  
                  while(repeat--) curr += temp;
              }
          }
          return curr;
      }
  };