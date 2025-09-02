// Reverse a Doubly Linked List

// Approach 1 
/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
      int l = 0 ; 
      int r = 0 ; 
      Node* temp2= head; 
      while(temp2->next){
          r++;
          temp2 = temp2->next; 
      }
      Node *temp1 = head; 
      while(l<=r){
          int temp = temp2->data; 
          temp2->data = temp1->data; 
          temp1->data = temp ; 
          temp2 = temp2->prev ; 
          temp1 = temp1->next; 
          l++;
          r--;
      }
       return head; 
    }
};





//Approach 2
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
       Node* curr = head; 
       Node *prev = nullptr;
       while(curr){
           Node *nextt = curr->next; 
           
           curr->next = prev; 
           curr->prev = nextt; 
           prev = curr; 
           curr = nextt; 
       }
        head = prev ;
        return head; 
       
    }
};








//Approach 3 
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
       vector<int>vec; 
       Node* temp = head; 
       while(temp){
           vec.push_back(temp->data);
           temp = temp->next; 
       }
       std::reverse(begin(vec), end(vec));
       temp = head; 
       int i = 0 ; 
       while(temp ){
           temp->data = vec[i++];
           temp = temp->next; 
       }
       return head; 
    }
};