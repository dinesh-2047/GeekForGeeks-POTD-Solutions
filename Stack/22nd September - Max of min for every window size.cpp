// Max of min for every window size


class Solution {
  public:
  vector<int> findPSE(vector<int> &arr){
      int n = arr.size();
      
      vector<int>pse(n , -1);
      stack<int>st; 
      
      for(int i = 0 ; i < n; i++){
          while(!st.empty()&& arr[st.top()] >= arr[i]){
              st.pop();
          }
          if(!st.empty()) pse[i] = st.top();
          st.push(i);
          
      }
      return pse; 
  }
  
  
  vector<int> findNSE(vector<int> &arr){
      int n = arr.size();
      vector<int>nse(n , n);
      
      stack<int>st; 
      
      for( int i = n - 1; i >= 0 ; i--){
          while(!st.empty() && arr[st.top() ] >= arr[i]){
              st.pop();
          }
          if(!st.empty()){
              nse[i] = st.top();
          }
          st.push(i);
      }
      return nse ; 
  }
  
  
    vector<int> maxOfMins(vector<int>& arr) {
       int n = arr.size();
       
       vector<int>pse = findPSE(arr);
       vector<int>nse = findNSE(arr);
       vector<int>result(n ,0);
       
       for(int i = 0 ; i <n; i++){
           int window_size= nse[i] - pse[i] - 1; 
           result[window_size - 1] = max(result[window_size - 1] , arr[i]);
       }
       
       for(int i =n -2; i >= 0 ; i--){
           result[i] = max(result[i] , result[i + 1]);
       }
       return result; 
        
    }
};