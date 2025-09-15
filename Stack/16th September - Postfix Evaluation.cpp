// Postfix Evaluation



class Solution {
  public:
 bool isOperator(string s){
     if(s == "+" || s== "-" || s== "*" || s== "/" || s=="^") return true; 
     else return false; 
 }
  
    int evaluatePostfix(vector<string>& arr) {
        int n = arr.size();
        
        stack<int>st; 
        
        for(int i = 0 ; i < n ; i++){
             if(isOperator(arr[i])){
                 int second = st.top();
                 st.pop();
                 int first = st.top();
                 st.pop();
                 
                 if(arr[i] == "*"){
                     st.push(first  * second);
                 }
                 if(arr[i] == "/"){
                      st.push(floor((double)first/ second));
                 }
                 if(arr[i] == "+"){
                      st.push(first + second);
                    
                 }
                 if(arr[i] == "-"){
                     st.push(first  - second);
                 }
                 if(arr[i] == "^"){
                     st.push(pow(first, second));
                 }
             }
             else st.push(stoi(arr[i]));
           
        }
        return st.top();
        
    }
};