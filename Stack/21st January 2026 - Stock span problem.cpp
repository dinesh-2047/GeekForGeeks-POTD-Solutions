// Stock span problem

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
         int n = arr.size();
        stack<int>st;  
        
        vector<int>result(n, 1);
        
        for(int i = 0 ; i  < n; i++){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                result[i] += result[st.top()];
                st.pop();
            }
            st.push(i);
        }
        return result; 
    }
};