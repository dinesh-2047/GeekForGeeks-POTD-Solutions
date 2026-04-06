// Huffman Encoding

class Node{
    public:
    int data;
    int idx;
    Node* left;
    Node* right;

    Node(int data, int idx){
        this->data = data;
        this->idx = idx;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class cmp{
    public:
    bool operator()(Node* a, Node* b){
        if(a->data == b->data)
            return a->idx > b->idx;
        return a->data > b->data;
    }
};

class Solution {
  public:
  void traverse(Node *root, string curr , vector<string> &result){
      if(!root) return;

      if(!root->left && !root->right){
          result.push_back(curr);
          return;
      }

      traverse(root->left, curr + '0', result);
      traverse(root->right, curr + '1', result);
  }

    vector<string> huffmanCodes(string &s, vector<int> f) {
        int n = f.size();

        if(n == 1){
            return {"0"};
        }

        priority_queue<Node*, vector<Node*>, cmp> pq;

        for(int i = 0; i < n; i++){
            pq.push(new Node(f[i], i));
        }

        while(pq.size() > 1){
            Node* left = pq.top(); pq.pop();
            Node* right = pq.top(); pq.pop();

            int newIdx = min(left->idx, right->idx);

            Node* new_node = new Node(left->data + right->data, newIdx);
            new_node->left = left;
            new_node->right = right;

            pq.push(new_node);
        }

        vector<string> result;
        traverse(pq.top(), "", result);

        return result;
    }
};