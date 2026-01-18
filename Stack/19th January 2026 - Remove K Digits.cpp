// Remove K Digits

class Solution {
  public:
    string removeKdig(string &s, int k) {
        int n = s.length();
        
        if(k >= n ) return "0";
        
        stack<char>st;
     
       string result = "";
       
       for(int i = 0 ; i < n ;i++){
           while(!st.empty() && k > 0  && st.top() > s[i] ){
               st.pop();
               k--;
           }
           st.push(s[i]);
       }
       
       
       while(k > 0 &&  !st.empty()){
           st.pop();
           k--;
       }
       
       
       while(!st.empty()){
           result += st.top();
           st.pop();
       }
       reverse(begin(result), end(result));
       
       int i =0 ; 
       while(i < result.length() && result[i] == '0') i++;
       result = result.substr(i);
       
       return result.empty() ? "0" : result; 
       
       
       
       
        
    }
};