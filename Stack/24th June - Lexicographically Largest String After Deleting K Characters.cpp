// Lexicographically Largest String After Deleting K Characters


class Solution {
  public:
    string maxSubseq(string& s, int k) {
        int n = s.length();
        
       stack<char>st; 
       
       for(int i = 0 ;i <n; i++){
           while(!st.empty() && st.top() < s[i] && k > 0 ){
               st.pop();
               k--;
           }
           st.push(s[i]);
       }
        
        while(!st.empty() && k > 0 ) {
            st.pop();
            k--;
        }
        
        string result = "";
        
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }
        reverse(begin(result), end(result));
        return result; 
    }
};
