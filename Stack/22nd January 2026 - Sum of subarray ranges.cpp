// Sum of subarray ranges

class Solution {
  public:
  int n ; 
  using ll = long long ; 
  vector<int> get_nse(vector<int> &arr){
      vector<int>nse(n, n);
      stack<int>st; 
      for(int i = n -1 ; i >= 0 ;i--){
          while(!st.empty() && arr[st.top()] > arr[i]){
              st.pop();
          }
          if(!st.empty())
          nse[i] = st.top();
          st.push(i);
      }
      return nse; 
  }
  vector<int> get_nge(vector<int> &arr){
      vector<int>nge(n, n);
      stack<int>st; 
      for(int i = n -1 ; i >= 0 ;i--){
          while(!st.empty() && arr[st.top()] < arr[i]){
              st.pop();
          }
            if(!st.empty())
          nge[i] = st.top();
          st.push(i);
      }
      return nge; 
  }
  
  vector<int>get_pse(vector<int> &arr){
       vector<int>pse(n, -1);
      stack<int>st; 
      for(int i = 0 ; i  < n; i++){
          while(!st.empty() && arr[st.top()] >= arr[i]){
              st.pop();
          }
            if(!st.empty())
          pse[i] = st.top();
          st.push(i);
      }
      return pse; 
  }
  vector<int>get_pge(vector<int> &arr){
       vector<int>pge(n, -1);
      stack<int>st; 
      for(int i = 0 ; i  < n; i++){
          while(!st.empty() && arr[st.top()] <= arr[i]){
              st.pop();
          }
            if(!st.empty())
          pge[i] = st.top();
          st.push(i);
      }
      return pge; 
  }
  
  
  
  int subMax(vector<int> &arr){
      vector<int>pge = get_pge(arr);
      vector<int>nge = get_nge(arr);
      
      ll sum = 0 ; 
      for(int i = 0 ; i < n; i++){
          int count = (i - pge[i]) * (nge[i] - i);
          sum += (count * arr[i]);
      }
      return sum ; 
  }
  int subMin(vector<int> &arr){
      vector<int>pse = get_pse(arr);
      vector<int>nse = get_nse(arr);
      
      ll sum = 0 ; 
      for(int i = 0 ; i < n; i++){
          int count = (i - pse[i]) * (nse[i] - i);
          sum += (count * arr[i]);
      }
      return sum ; 
  }
    int subarrayRanges(vector<int>& arr) {
        n = arr.size();
        return subMax(arr) - subMin(arr);
        
    }
};