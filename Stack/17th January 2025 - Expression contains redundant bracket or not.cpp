// Expression contains redundant bracket or not


class Solution {
  public:
  bool isSign(char ch){
      return ch == '+' || ch == '-' || ch == '*' || ch == '/';
  }
  
    bool checkRedundancy(string &s) {
        int n = s.length();
        
        stack<char>st; 
        
        for(int i = 0 ; i < n; i++){
            if(s[i] == ')'){
                bool sign_found = false; 
                while(!st.empty() && st.top() != '('){
                    if(isSign(st.top())){
                        sign_found = true; 
                    }
                    st.pop();
                }
                st.pop();
                if(!sign_found) return true; 
                
                
            }
            else st.push(s[i]);
        }
        return false; 
        
    }
};
