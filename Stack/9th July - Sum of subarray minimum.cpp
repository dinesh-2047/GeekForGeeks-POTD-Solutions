// Sum of subarray minimum


class Solution {
public:
vector<int>nextSmallest(vector<int> &arr){
       int n = arr.size();
       vector<int>nse(n);

       stack<int>st; 
       for(int i = n-1; i >=0; i--){
           while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
           if(st.empty()) nse[i] = n;
           else nse[i] = st.top();
           st.push(i);
       }
       return nse; 
}

vector<int> prevSmallest(vector<int> &arr){
        int n = arr.size();
        vector<int>pse(n);

        stack<int>st; 
        for(int i = 0 ;  i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(st.empty()) pse[i] = -1;
            else pse[i] = st.top();
            st.push(i);
        }
        return pse; 
}
    int sumSubMins(vector<int>& arr) {
        int n = arr.size();

        vector<int>pse = prevSmallest(arr);
        vector<int>nse = nextSmallest(arr);
        int result = 0 ; 

        for(int i = 0 ; i <n; i++){
            int count = (i-pse[i])*(nse[i] - i);
            result = result + (count * arr[i]);
        }

        return result; 
    }
};