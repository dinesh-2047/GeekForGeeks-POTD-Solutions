// Histogram Max Rectangular Area


class Solution {
    public:
  vector<int>getNSE(vector<int> &heights){
      int n = heights.size();
      
      stack<int>st;
      vector<int>NSE(n);
      
      for(int i = n-1 ; i>=0; i--){
          if(st.empty()) NSE[i] = n;
          
          else{
              while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
          }
          
          if(st.empty()) NSE[i] = n;
          else NSE[i] = st.top();
          
          st.push(i);
      }
      return NSE;
  }  
    
    
   vector<int> getPSE(vector<int> &heights){
       int n = heights.size();
       stack<int>st; 
       vector<int>PSE(n);
       
       for(int i = 0 ; i<n; i++){
           if(st.empty()) PSE[i] = -1;
           else{
               while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
               
           }
           if(st.empty()) PSE[i] = -1; 
           else PSE[i] =st.top();
           st.push(i);
       }
       return PSE; 
   } 
    
      int getMaxArea(vector<int> &arr) {
         int n = arr.size();
         
         vector<int>NSE = getNSE(arr);
         vector<int>PSE = getPSE(arr);
         
         vector<int>width(n);
         
         for(int i = 0 ; i<n; i++){
             width[i] = NSE[i] - PSE[i] -1;
             
         }
         
         int maxArea = 0;
         for(int i = 0 ; i<n; i++){
             maxArea = max(maxArea, width[i] * arr[i]);
         }
         return maxArea; 
      }
  };
  
