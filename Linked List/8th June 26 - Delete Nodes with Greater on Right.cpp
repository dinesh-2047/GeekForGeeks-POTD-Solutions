// Delete Nodes with Greater on Right


/* Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
public:
    int max_val = INT_MIN;
    Node* compute(Node* head) {
        if (!head)
            return NULL;

        head->next = compute(head->next);

        if (head->data < max_val)
            return head->next;

        max_val = max(max_val, head->data);
        return head;
    }
};