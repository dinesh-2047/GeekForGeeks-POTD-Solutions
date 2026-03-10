// Subarrays with First Element Minimum

class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        int n = arr.size();
        int result = 0 ; 
        vector<int>nse (n, n); 
        stack<int>st; 
        for(int i = n-1; i  >= 0 ; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            
            if(!st.empty()) nse[i] = st.top();
            result += (nse[i] - i );
            st.push(i);
        }
        return result; 
        
        
    }
};