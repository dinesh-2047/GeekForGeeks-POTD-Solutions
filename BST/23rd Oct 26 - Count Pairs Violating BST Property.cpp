// Count Pairs Violating BST Property

/* BST Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
public:
    long long result = 0;
    vector<int> vec, temp;

    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        vec.push_back(root->data);
        inorder(root->right);
    }

    void merge(int l, int m, int r) {
        int i = l, j = m + 1, k = l;

        while (i <= m && j <= r) {
            if (vec[i] <= vec[j]) {
                temp[k++] = vec[i++];
            } else {
                temp[k++] = vec[j++];
                result += m - i + 1;
            }
        }

        while (i <= m) temp[k++] = vec[i++];
        while (j <= r) temp[k++] = vec[j++];

        for (int p = l; p <= r; p++)
            vec[p] = temp[p];
    }

    void mergeSort(int l, int r) {
        if (l >= r) return;

        int m = l + (r - l) / 2;
        mergeSort(l, m);
        mergeSort(m + 1, r);
        merge(l, m, r);
    }

    int pairsViolatingBST(Node* root) {
        vec.clear();
        result = 0;
        inorder(root);
        temp.resize(vec.size());
        mergeSort(0, (int)vec.size() - 1);
        return (int)result;
    }
};