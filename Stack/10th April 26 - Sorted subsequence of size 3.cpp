// Sorted subsequence of size 3

class Solution {
  public:
  int n ; 
  vector<int> get_pse(vector<int> &arr){
      vector<int>pse(n , -1);
      stack<int>st; 
      for(int i = 0; i < n; i++){
          while(!st.empty() && arr[st.top()]>=arr[i]){
              st.pop();
          }
          if(!st.empty()) pse[i] = st.top();
          st.push(i);
      }
      return pse; 
  }
  
  vector<int> get_nse(vector<int> &arr){
      vector<int> nse(n , n);
      stack<int>st; 
      for(int i = n - 1; i  >= 0 ; i--){
          while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
          if(!st.empty()) nse[i] = st.top();
          st.push(i);
      }
      return nse; 
  }
  
    vector<int> find3Numbers(vector<int> &arr) {
        n = arr.size();
       vector<int>pse = get_pse(arr);
       vector<int>nse = get_nse(arr);
       
       for(int i =0 ; i < n; i++){
           if(pse[i] != -1 && nse[i] != n ){
               return {arr[pse[i]], arr[i], arr[nse[i]]};
           }
       }
       return {};
    }
};