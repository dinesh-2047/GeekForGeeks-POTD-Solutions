// Min Add to Make Parentheses Valid\



// Approach 1  : using stack 
class Solution {
  public:
    int minParentheses(string& s) {
        int n = s.length(); 
        
        stack<char>st; 
        
        for(int i = 0 ; i < n ; i++){
            if(s[i] == ')'){
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }
                else st.push(')');
            }
            else st.push('(');
           
        }
        return st.size();

        
    }
};




//appraoch  2 : using two counters
class Solution {
  public:
    int minParentheses(string& s) {
        int n = s.length(); 
        
        int balance = 0 ; 
        int not_matching = 0 ; 
        
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '('){
                balance++;
            }
            else{
                balance--;
                if(balance < 0 ){
                    not_matching++;
                    balance = 0; 
                }
            }
           
        }
        return balance + not_matching; 
        
    }
};