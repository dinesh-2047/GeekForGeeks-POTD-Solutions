// Maximum of minimum for every window size


class Solution {
    public: 
   vector<int> getPrevSmaller(vector<int>& arr){
       vector<int>prev(arr.size());
       stack<int>st; 
       
       for(int i = 0 ; i<arr.size(); i++){
           if(st.empty()) prev[i] = -1; 
           else{
               while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
               
              
           }
            if(st.empty()) prev[i] = -1 ;
               else prev[i] = st.top();
               
               st.push(i);
       }
       return prev; 
   }
   
   
   vector<int> getNextSmaller(vector<int> &arr){
       vector<int>next(arr.size());
       stack<int>st; 
       
       for(int i = arr.size()-1 ; i>=0; i--){
           if(st.empty()) next[i] = arr.size(); 
           else{
               while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
           }
           if(st.empty()) next[i] =arr.size();
           else next[i] =st.top();
           
           st.push(i);
       }
       return next; 
   }
    
    
      vector<int> maxOfMins(vector<int>& arr) {
         int n = arr.size();
         vector<int>ans(n,0);
         
         vector<int>prevSmaller = getPrevSmaller(arr);
         vector<int>nextSmaller = getNextSmaller(arr);
         
         for(int i = 0 ; i<n; i++){
             int window_size = nextSmaller[i] - prevSmaller[i] - 1;
             ans[window_size-1]= max(ans[window_size-1], arr[i]);
         }
         
         for(int i = n-2; i>=0; i--){
             ans[i]= max(ans[i], ans[i+1]);
         }
         return ans; 
      }
  };