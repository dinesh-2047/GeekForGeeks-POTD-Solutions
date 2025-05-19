// Burning Tree


class Solution {
  public:
    int burnfun(Node* node,Node* targetnode,map<Node*,Node*>&parent_track){
        unordered_map<Node*,bool> visited;
        queue<Node*> q;
        q.push(targetnode);
        int timeinterval=0;
        visited[targetnode]=true;
        while(!q.empty()){
            int size=q.size();
            int burn=0;
            for(int i=0;i<size;i++){
                Node* n=q.front();
                q.pop();
                if(n->left&&!visited[n->left]){
                    visited[n->left]=true;//visited means we are burning
                    burn=1;
                    q.push(n->left);
                }
                if(n->right&&!visited[n->right]){
                    visited[n->right]=true;
                    burn=1;
                    q.push(n->right);
                }
                if(parent_track[n]&&!visited[parent_track[n]]){
                    burn=1;
                    visited[parent_track[n]]=true;
                    q.push(parent_track[n]);
                }
            }
            if(burn){timeinterval++;}
        }
        return timeinterval;
        
    }
    Node* makechildparentconnection(Node* node,map<Node*,Node*>&parent_track,int target){
        queue<Node*> q;
        q.push(node);
        Node*targetnode=nullptr;
        while(!q.empty()){
            Node* n=q.front();
            q.pop();
            if(n->data==target){targetnode=n;}
            if(n->left!=nullptr){
                parent_track[n->left]=n;
                q.push(n->left);
            }
            if(n->right!=nullptr){
                parent_track[n->right]=n;
                q.push(n->right);
            }
        }
        return targetnode;
    }
    int minTime(Node* root, int target) {
        // code here
        map<Node*,Node*> parent_track;
        Node* targetnode=makechildparentconnection(root,parent_track,target);
        return burnfun(root,targetnode,parent_track);
    }
};