// Print leaf nodes from preorder traversal of BST



class Solution {
  public:
    vector<int> leafNodes(vector<int>& preorder) {
        int n = preorder.size();
        stack<int>st; 
        vector<int>result; 
        
        for(int i = 0 ; i<n-1; i++){
            int curr = preorder[i];
            int next = preorder[i+1];
            
            bool isLeaf = false; 
            
            if(curr > next) st.push(curr);
            
            else{
                while(!st.empty() && next > st.top()){
                    st.pop();
                    isLeaf = true; 
                }
               
            }
             if(isLeaf)
                result.push_back(curr);
        }
        result.push_back(preorder[n-1]);
        return result; 
    }
};