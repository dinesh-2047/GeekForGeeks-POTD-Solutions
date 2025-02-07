class Solution {
    public:
   bool isLeaf(Node* root){
       if(root->left == nullptr && root->right== nullptr) return true;
       else return false;
   }
    
   void leftBoundary(Node* root, vector<int>&ans){
       Node* curr = root->left;
       
       while(curr != nullptr){
           if(!isLeaf(curr)) ans.push_back(curr->data);
           
           if(curr->left) curr = curr ->left;
           else curr = curr -> right;
       }
   }
   
   void rightBoundary(Node* root, vector<int>&ans){
       Node* curr = root->right;
       vector<int>v;
       
       while(curr != nullptr){
           if(!isLeaf(curr)) v.push_back(curr->data);
           
           if(curr->right) curr = curr ->right;
           else curr = curr ->left;
           
          
       }
       for(int i = v.size()- 1 ; i>=0 ; i--){
           ans.push_back(v[i]);
       }
   }
   
   
   void LeafNodes(Node* root, vector<int>&ans){
       if(isLeaf(root)) {
           ans.push_back(root->data);
           return;
       }
       
       if(root->left) LeafNodes(root->left,ans);
       if(root->right) LeafNodes(root->right, ans);
       
   }
    
    
    
      vector<int> boundaryTraversal(Node *root) {
         vector<int>ans;
         if(root == nullptr) return ans;
         
         if(!isLeaf(root)) ans.push_back(root->data);
         
         leftBoundary(root, ans);
          LeafNodes(root, ans);
         rightBoundary(root,ans);
        
         
         return ans;
      }
  };