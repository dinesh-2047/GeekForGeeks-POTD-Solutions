// Node and Ancestor Max Diff

/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/
class Solution {
public:
    int result = INT_MIN;

    void solve(Node* root, int mx) {
        if (!root) return;

        result = max(result, mx - root->data);
        mx = max(mx, root->data);

        solve(root->left, mx);
        solve(root->right, mx);
    }

    int maxDiff(Node* root) {
        if (!root) return 0;

        solve(root->left, root->data);
        solve(root->right, root->data);

        return result;
    }
};
  
  