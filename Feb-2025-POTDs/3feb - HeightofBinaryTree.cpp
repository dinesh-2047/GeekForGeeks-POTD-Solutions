//height of a binary tree 

class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
       if(node== nullptr) return -1;
       
       return 1+max(height(node->left), height(node->right));
    }
};