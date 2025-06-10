// Remove the balls


class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        int n = color.size();
        
        stack<pair<int, int>>st; 
        
        st.push({color[0], radius[0]});
        
       for(int i = 1; i <n; i++){
           if(!st.empty() && st.top().first == color[i] && st.top().second == radius[i]){
               st.pop();
           }
           else st.push({color[i], radius[i]});
       }
       if(st.empty()) return 0; 
       else return st.size();
       
        
    }
};