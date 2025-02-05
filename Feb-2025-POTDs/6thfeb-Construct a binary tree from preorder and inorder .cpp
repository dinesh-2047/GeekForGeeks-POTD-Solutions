
class Solution {
  public:
    Node* solve(vector<int>&inorder, vector<int>&preorder, int start, int end , int& index){
        if(start>end) return nullptr;
        
        int rootVal = preorder[index];
        int i = start ;  
        
        for( ;i <=end; i++){
            if(inorder[i] == rootVal){
                break;
            }
            
        }
        index++;
        Node* root = new Node(rootVal);
        root->left = solve(inorder, preorder, start ,  i-1, index);
        root->right = solve(inorder, preorder, i+1, end, index );
        return root;
    }
    
    
    
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int n = inorder.size();
        
        int index = 0 ; 
        
        return solve(inorder, preorder, 0  ,n-1 , index);
        
        
    }
};

