// Longest Subarray Length


class Solution {
  public:
  vector<int> findNGE(vector<int> &arr){
      int n = arr.size();
      vector<int>nge(n, n);
      stack<int>st; 
      for(int i = n-1 ; i  >= 0 ; i--){
          while(!st.empty() && arr[st.top()] <= arr[i] ){
              st.pop();
          }
          if(!st.empty()) nge[i] = st.top();
          st.push(i);
      }
      return nge; 
  }
  
  vector<int> findPGE(vector<int> &arr){
      int n = arr.size();
      stack<int>st; 
      vector<int>pge(n, -1); 
      
      for(int i = 0 ; i < n; i++){
          while(!st.empty() && arr[st.top()] <= arr[i]){
              st.pop();
          }
          if(!st.empty()) pge[i] = st.top();
          st.push(i);
      }
      return pge; 
  }
  
    int longestSubarray(vector<int>& arr) {
       int n = arr.size();
       
       vector<int>nge = findNGE(arr);
       vector<int>pge = findPGE(arr);
       
        int result = 0 ; 
       for(int i = 0 ; i < n; i++){
        int len = nge[i] -pge[i] - 1;
           
           if(arr[i] <= len ){
               result = max(result , len);
           }
       }
       return result; 
        
    }
};