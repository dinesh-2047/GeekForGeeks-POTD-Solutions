// Decode the string



class Solution {
  public:
    string decodedString(string &s) {
       int n = s.length();
       
       stack<string>st; 
       
       for(int i = 0 ; i < n; i++){
           if(s[i] == ']'){
               string str = "";
               while(!st.empty() && st.top()!="["){
                  str = st.top() + str;
                  st.pop();
               }
               st.pop();
               int k =stoi(st.top());
     
               st.pop();
               string temp = str; 
               for(int j = 0 ; j < k-1 ; j++ ){
                   str = temp + str ; 
               }
           
               st.push(str);
           }
        
           
           else{
               if(isdigit(s[i])){
                   string num =  "";
                   while(isdigit(s[i])){
                       num.push_back(s[i]);
                       i++;
                   }
                   i--;
                   st.push(num);
               }
               else
               st.push(string(1, s[i]));
           }
       }
       
       string result = "";
       while(!st.empty()){
           result = st.top() + result; 
           st.pop();
       }
       
 
       return result; 
        
    }
};