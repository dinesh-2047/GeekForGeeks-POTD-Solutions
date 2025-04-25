// Is Binary Tree Heap 

// User Function template for C++

// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
    public:
    void countNode(Node *tree, int &nodeCount){
        if(tree == nullptr) return  ; 
        
        nodeCount++;
        countNode(tree->left , nodeCount);
        countNode(tree->right, nodeCount);
    }
    
    
    bool isCBT(Node* tree, int i , int nodeCount){
        if(tree == nullptr) return true; 
        
        if(i >= nodeCount) return false; 
        
        bool leftt = isCBT (tree -> left , 2*i +1 , nodeCount);
        bool rightt = isCBT(tree->right , 2*i + 2, nodeCount);
        
        return leftt and rightt;
    }
    
    
    bool isMaxHeap(Node *tree ){
        //is leaf node
        if(tree->left == nullptr && tree->right == nullptr) return true; 
        
        if(tree->left && tree -> right == nullptr) {
            return tree->data > tree->left->data;
        }
        
        return tree->data > tree->left->data && tree->data > tree->right->data && isMaxHeap(tree->left ) && isMaxHeap(tree->right);
    }
    
      bool isHeap(Node* tree) {
          if(tree == nullptr) return true; 
           
           int nodeCount = 0;
           countNode(tree, nodeCount);
          
          if(isCBT (tree ,0 , nodeCount) && isMaxHeap(tree)){
              return true; 
              
          }
          
          else return false; 
          
      }
  };