// Next element with greater frequency


class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        int n = arr.size();
        
        stack<int>st; 
        unordered_map<int , int>mp; 
        for(auto &x :arr) mp[x]++;
        
        vector<int>result(n, -1);
        
        for(int i = n-1 ; i  >= 0; i--){
            while(!st.empty() && mp[arr[st.top()]] <= mp[arr[i]]) st.pop();
            
            if(!st.empty()) result[i] = arr[st.top()];
            
            st.push(i);
           
        }
        
        return result; 
        
        
    }
};
