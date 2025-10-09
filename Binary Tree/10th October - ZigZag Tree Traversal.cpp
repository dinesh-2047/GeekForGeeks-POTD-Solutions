// ZigZag Tree Traversal

/*
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        // code here
        bool righttoleft = false; 
        vector<int>result;
        queue<Node*>q; 
        
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int>temp ;
            while(n--){
                Node* curr = q.front();
                 q.pop();
                temp.push_back(curr->data);
               
                 if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
            }
           
            if(righttoleft){
                reverse(temp.begin(), temp.end());
                
                righttoleft = false; 
            }
            else{
                righttoleft = true; 
            }
            for(auto &t : temp){
                    result.push_back(t);
                }
        }
        return result; 
    }
};