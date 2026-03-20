// Predecessor and Successor


/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        
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

