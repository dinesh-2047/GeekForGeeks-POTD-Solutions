// Number of Turns in Binary Tree

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
}; */

class Solution {
public:
    bool findPath(Node* root, int target, vector<int>& path) {
        if (!root) return false;
        if (root->data == target) return true;

        path.push_back(0);
        if (findPath(root->left, target, path))
            return true;
        path.pop_back();

        path.push_back(1);
        if (findPath(root->right, target, path))
            return true;
        path.pop_back();

        return false;
    }

    int numberOfTurns(Node* root, int p, int q) {
        vector<int> pathP, pathQ;
        findPath(root, p, pathP);
        findPath(root, q, pathQ);

        int i = 0;
        while (i < pathP.size() && i < pathQ.size() &&
               pathP[i] == pathQ[i]) {
            i++;
        }

        vector<int> path;

        for (int j = pathP.size() - 1; j >= i; j--)
            path.push_back(pathP[j]);

        for (int j = i; j < pathQ.size(); j++)
            path.push_back(pathQ[j]);

        int turns = 0;

        for (int j = 1; j < path.size(); j++) {
            if (path[j] != path[j - 1])
                turns++;
        }

        return turns == 0 ? -1 : turns;
    }
};