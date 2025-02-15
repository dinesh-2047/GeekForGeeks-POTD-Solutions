// Serialize and deserialize a binary tree


// we can solve this problem by using all types of traversals 

// but i feel inorder is easy and short for me 

/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution {
    public:
  void inorder(Node* root, vector<int>&v){
      if(root == nullptr) return ;
      
      inorder(root->left, v);
      v.push_back(root->data);
      inorder(root->right, v);
  }
  
      vector<int> serialize(Node *root) {
          vector<int>v;
          inorder(root, v );
          return v; 
      }
  
   Node* buildTree (vector<int>&arr, int start , int end ){
       
       if(start > end) return nullptr;
       
       int mid = (start + end) / 2;
          Node* root = new Node(arr[mid]);
  
          root->left = buildTree(arr, start, mid - 1);
          root->right = buildTree(arr, mid + 1, end);
  
          return root;
   }
   
   
      Node *deSerialize(vector<int> &arr) {
         return buildTree(arr, 0  ,arr.size()-1);
          
      }
  };

  