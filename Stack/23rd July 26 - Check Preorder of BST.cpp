// Check Preorder of BST

class Solution {
  public:
    bool canRepresentBST(vector<int> &arr) {
        int n = arr.size();
        
        stack<int> st; 
        st.push(arr[0]);
        
        int mini = -1; 
        
        for(int i = 1; i  < n; i++){
            int temp = -1; 
            
            while(!st.empty() && st.top() < arr[i]){
                temp = st.top();
                st.pop();
            }
            
            if(temp == -1){
                if(arr[i] < mini) return false ; 
            }
            else mini = temp ; 
            st.push(arr[i]);
        }
        return true; 
        
    }
};