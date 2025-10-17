// Median of BST


// Approach 1 using vec ;

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  void inorder(Node *root, vector<int> &vec){
      if(!root) return ; 
      inorder(root->left, vec);
      vec.push_back(root->data);
      inorder(root->right, vec);
  }
    int findMedian(Node* root) {
        vector<int>vec; 
        inorder(root, vec);
        int n = vec.size();
        if(n%2 == 0 ){
            return vec[(n / 2)-1];
        }
        else return vec[((n + 1)/2)-1];
    }
};






//Approach 2 without vec
/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:

  int getLen(Node *root){
      if(!root) return 0 ; 
      return getLen(root->left) + getLen(root->right) + 1;
  }
  void solve(Node* root , int &i ,  int &n , int &result){
      if(!root) return ;
      
      solve(root->left, i, n , result);
      i++;
      if(i == n){
          result = root->data; 
          return ; 
      }
      solve(root->right , i , n , result);
  }
  
    int findMedian(Node* root) {
        int len = getLen(root);
        
        int n = 0 ; 
        if(len%2 == 0 ){
            n = len / 2; 
        }
        else {
            n = (len + 1)/2;
        }
        
        int result = 0 ; 
        int i = 0 ; 
        solve(root ,i , n , result );
        
        return result ;
    }
};