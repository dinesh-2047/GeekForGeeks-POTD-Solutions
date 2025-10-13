// Sum of Nodes in BST Range


// Approach 1
class Solution {
  public:
  void inorder(Node *root, vector<int> &vec ){
      if(!root) return  ; 
      
      inorder(root->left, vec);
      vec.push_back(root->data);
      inorder(root->right , vec);
  }
    int nodeSum(Node* root, int l, int r) {
        vector<int>vec; 
        inorder(root, vec);
      
        
        int st = lower_bound(begin(vec), end(vec), l) -begin(vec);
        int e = lower_bound(begin(vec), end(vec), r)-begin(vec);
        if(e >= vec.size() ){
            e = vec.size()-1; 
        }
       
        if(vec[e] > r){
            e--; 
        }
        
        int result = 0 ; 
        for(int i = st; i <= e; i++){
            result += vec[i];
        }
        return result; 
    }
};






//Approach 2 
/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void solve(Node* root, int l, int r,int&sum){
        if(!root)return ;
        if(root->data>=l&&root->data<=r)sum+=root->data;
        if(root->data>=l)solve(root->left,l,r,sum);
        if(root->data<=r)solve(root->right,l,r,sum);
    }
    int nodeSum(Node* root, int l, int r) {
        int sum=0;
        solve(root,l,r,sum);
        return sum;
    }
};
