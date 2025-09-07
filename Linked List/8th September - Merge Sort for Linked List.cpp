// Merge Sort for Linked List


/*
class Node {
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
  Node *split(Node *head){
      Node *slow = head; 
      Node *fast = head; 
      
      while(slow && fast && fast ->next){
         
          fast = fast->next->next; 
          if(fast){
               slow = slow->next; 
          }
      }
      
      
      Node *temp = slow->next ;
      slow->next = nullptr; 
      
      
      return temp ; 
      
      
      
  }
  
  
  
  Node *merge(Node* first , Node* second){
      if(first == nullptr ) return second; 
      if(second == nullptr) return first; 
      
      if(first->data < second->data){
          first->next = merge(first->next, second);
          return first; 
      }
      else {
          second->next = merge(first, second->next);
          return second; 
      }
  }
  
  
  Node* merge_sort(Node* head){
      if(head == nullptr || head ->next == nullptr) return head;
      
      Node *second = split(head);
      
      head = merge_sort(head);
      second = merge_sort(second);
      
     return merge(head, second);
  }
  
  
    Node* mergeSort(Node* head) {
       
       return merge_sort(head);
        
    }
};