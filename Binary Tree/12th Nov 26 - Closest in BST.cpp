// Closest in BST


/* Structure of a Binary Search Tree node
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
	int minDiff(Node *root, int k) {
		int result = 1e9;
		Node* node = root;
		while (node) {
			if (node->data == k) {
				return 0;
			} else if (k>node->data) {
				result = min(result, abs(k - node->data));
				node = node->right;
			} else {
				result = min(result, abs(k - node->data));
				node = node->left;
			}
		}
		return result;
	}
};
