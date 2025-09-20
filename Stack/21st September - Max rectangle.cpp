// Max rectangle


class Solution {
  public:
vector<int> findPSE(vector<int> arr){
    int n = arr.size();
    
    vector<int>pse(n , -1);
    stack<int>st; 
    
    for(int i = 0; i < n ; i++){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        if(!st.empty()){
            pse[i] = st.top();
        }
        
        st.push(i);
    }
    return pse;
}  


vector<int> findNSE(vector<int> arr){
    int n = arr.size();
    vector<int>nse(n , n);
    stack<int>st ;
    
    for(int i = n-1; i >= 0 ; i--){
       while(!st.empty() && arr[st.top()] >= arr[i]){
           st.pop();
           
       }
       
       if(!st.empty()) {
           nse[i] = st.top();
       }
       st.push(i);
    }
    return nse; 
}
  
  
 int area(vector<int> histogram){
     int n = histogram.size();
     
     vector<int>pse = findPSE(histogram);
     vector<int>nse = findNSE(histogram);
     
     int maxArea = 0 ; 
     
     for(int i = 0 ; i  < n; i++){
         int l = histogram[i];
         
         int b = nse[i] - pse[i] - 1;
         maxArea = max(maxArea, l *b);
         
     }
     return maxArea; 
 }
  
  
    int maxArea(vector<vector<int>> &mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<int>histogram(n, 0); 
        int result = 0 ; 
        
        for(int i = 0 ; i  < m; i++ ){
            for(int j = 0 ;j < n; j++){
                if(mat[i][j] == 1){
                    histogram[j]++;
                }
                else histogram[j] = 0 ; 
            }
            result = max(result , area(histogram));
            
        }
        return result; 
        
    }
};