// Next element with greater frequency


class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        int n = arr.size();
        
        unordered_map<int , int>mp ; 
        
        for(int i = 0; i < n; i++){
            mp[arr[i]]++;
        }
        
        vector<int>result(n);
        result[n-1] = -1; 
        stack<int>st; 
        st.push(n-1);
        
        for(int i = n-2; i >= 0; i--){
            while(!st.empty() && mp[arr[st.top()]] <= mp[arr[i]]){
                st.pop();
            }
            if(st.empty() ) result[i] = -1; 
            else result[i] = arr[st.top()];
            
            st.push(i);
        }
        return result; 
        
    }
};
