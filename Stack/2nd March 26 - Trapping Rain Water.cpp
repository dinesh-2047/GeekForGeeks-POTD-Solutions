// Trapping Rain Water

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();

        stack<int>st; 

        int water = 0 ; 

        for(int i = 0 ; i  < n; i++){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                int bottom = st.top();
                st.pop();

                if(st.empty()) break; 

                int left = st.top();
                int width = i - left - 1;
                int boundedarr = min(arr[left], arr[i]) - arr[bottom];

                water += width * boundedarr; 
            }
            st.push(i);
        }
        return water; 
        
    }
};