// Maximum People Visible in a Line

class Solution {
  public:
  int n ;
  
  vector<int> get_nge(vector<int> &arr){
      vector<int>nge(n , n); 
      stack<int>st; 
      
      for(int i = n-1 ; i >= 0 ; i--){
          while(!st.empty() && arr[st.top()] < arr[i]) st.pop();
          if(!st.empty()) nge[i] = st.top();
          st.push(i);
      }
      return nge; 
  }
  
  vector<int> get_pge(vector<int> &arr){
      vector<int>pge(n , -1);
      stack<int>st; 
      for(int i = 0 ; i  < n; i++){
          while(!st.empty() && arr[st.top()] < arr[i]) st.pop();
          if(!st.empty()) pge[i] = st.top();
          st.push(i);
      }
      return pge; 
  }
  
 
    int maxPeople(vector<int> &arr) {
         n = arr.size();
         
         vector<int>nge = get_nge(arr);
         vector<int>pge = get_pge(arr);
         
         
         int result = 0 ; 
         for(int i = 0 ; i < n; i++){
             result = max(result,  (nge[i] - i) + (i - pge[i] - 1));
         }
         return result; 
         
         
        
    }
};