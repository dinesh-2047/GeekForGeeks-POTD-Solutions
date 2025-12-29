// Add Number Linked Lists

/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
private:
    Node *reverse(Node *head)
    {
        Node *current = head;
        Node *prev = nullptr;
        Node *next = nullptr;
        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    void insertattail(struct Node *&head, struct Node *&tail, int value)
    {
        Node *temp = new Node(value);
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    Node *add(struct Node *num1, struct Node *num2)
    {
        int carry = 0;
        Node *anshead = nullptr;
        Node *anstail = nullptr;
        while (num1 != nullptr || num2 != nullptr || carry != 0)
        {

            int val1 = 0;
            if (num1 != nullptr)
            {
                val1 = num1->data;
            }
            int val2 = 0;
            if (num2 != nullptr)
            {
                val2 = num2->data;
            }
            int sum = carry + val1 + val2;
            int digit = sum % 10;
            insertattail(anshead, anstail, digit);
            carry = sum / 10;
            if (num1 != nullptr)
            {
                num1 = num1->next;
            }
            if (num2 != nullptr)
            {
                num2 = num2->next;
            }
        }

        return anshead;
    }

public:
    // Function to add two numbers represented by linked list.
    Node *addTwoLists(struct Node *num1, struct Node *num2)
    {

        num1 = reverse(num1);
        num2 = reverse(num2);
    
        Node *ans = add(num1, num2);
        ans = reverse(ans);
        
        while(ans && ans->data == 0) ans = ans->next; 
        return ans;
    }
};
