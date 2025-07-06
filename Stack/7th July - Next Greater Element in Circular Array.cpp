// Next Greater Element in Circular Array


class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        int n= arr.size();
        
        stack<int>st; 
        
        for(int i = n-1; i >=0; i--){
            st.push(i);
        }
        
        vector<int>result(n);
        
        for(int i = n-1; i >=0; i--){
            while(!st.empty() &&arr[ st.top()] <= arr[i]) st.pop();
            
            if(st.empty()){
                result[i] = -1; 
            }
            else result[i] = arr[st.top()];
            
            st.push(i);
        }
        
        return result; 
        
    }
};