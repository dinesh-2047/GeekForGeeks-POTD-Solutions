// Level Order in spiral form


/* A binary tree node has data, pointer to left child
   and a pointer to right child
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */
class Solution {
  public:
    vector<int> findSpiral(Node* root) {
       vector<int>result; 
       
       queue<Node*>q; 
       q.push(root) ;
       
       int level = 0 ; 
       while(!q.empty()){
           int n = q.size();
            vector<int>temp ;
           while(n--){
               
               auto curr = q.front();
               q.pop();
               
               temp.push_back(curr->data);
               
               if(curr->left) q.push(curr->left);
               if(curr->right) q.push(curr->right);
               
           }
           if(level%2==0) reverse(temp.begin(), temp.end());
           for(int i = 0 ; i<temp.size(); i++){
               result.push_back(temp[i]);
           }
           level++;
       }
       
       return result; 
        
    }
};