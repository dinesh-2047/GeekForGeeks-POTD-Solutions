// Maximum path sum from any node


class Solution {
    public:
    int maxSum ;
    int solve(Node* root){
        if(root == nullptr ) return 0;
        
        int l = solve(root->left);
        int r = solve(root->right);
        
        int neeche_hi_milgya_answer = l +r + root->data;
        
        int koi_ek_acha = max(l,r) + root->data;
        int only_root_acha = root->data;
        
        maxSum = max({maxSum , neeche_hi_milgya_answer, koi_ek_acha, only_root_acha});
        
        //most important part ; 
        return max(koi_ek_acha, only_root_acha);
    }
    
    
      int findMaxSum(Node *root) {
          maxSum = INT_MIN;
          solve(root);
          return maxSum;
      }
  };