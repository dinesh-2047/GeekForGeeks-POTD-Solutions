// Predecessor and Successor



// Approach 1 -> inorder traversal and space
class Solution {
  public:

  
 void inorder (Node* root, vector<Node*> &inorderr){
      if(root == nullptr) return; 
      
     
      inorder(root->left, inorderr);
       inorderr.push_back(root);
      inorder(root->right , inorderr);
  }
    vector<Node*> findPreSuc(Node* root, int key) {
        vector<Node*>result; 
        
        vector<Node*>inorderr ;
        inorder(root , inorderr);
       
        
        Node* pre = new Node(-1);
        Node* succ = new Node(-1);
        int n = inorderr.size();
        
       int i = 0;
       while(i<n && inorderr[i]->data <= key) i++;
       
       if(i < n)
       succ = inorderr[i];
       
       i = 0 ; 
       while(i<n && inorderr[i]->data < key ){
          pre = inorderr[i];
          i++;
       } 
      
      return {pre, succ}; 
        
    }
};



// approach 2 
class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
      
        
        Node* pre = new Node(-1);
        Node* succ = new Node(-1);
        
        Node* temp = root; 
        
        while(temp){
            if(temp->data < key) {
                pre = temp; 
                temp = temp->right ; 
            }
            else temp = temp->left; 
        }
        
        
        temp = root ; 
        while(temp){
            if(temp->data > key){
                succ = temp ; 
                temp = temp->left; 
            }
            else temp = temp->right ; 
        }
        return {pre , succ};
    }
};