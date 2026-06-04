// Lexicographically smallest after removing k


class Solution {
  public:
    string lexicographicallySmallest(string &s, int k) {
       int n = s.length();
       
       k = (n&(n-1))?k*2:k/2;
       
       stack<char>st; 
       
       if(k > n ) return "-1"; 
       
       for(int i = 0 ; i  < n; i++){
           if(st.empty()){
               st.push(s[i]);
           }
           else {
               while(k > 0 && !st.empty() && s[i] < st.top()){
                   st.pop();
                   k--;
               }
               st.push(s[i]);
           }
       }
       
       string result = "";
       while(!st.empty() && k > 0 ){
           st.pop();
           k--;
       }
       
       while(!st.empty()){
           result = st.top() + result; 
           st.pop();
       }
       return result == "" ? "-1" : result; 
    }
};