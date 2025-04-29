// Find length of Loop


class Solution {
    public:
  
      int countNodesinLoop(Node *head) {
          if(head == nullptr) return 0 ; 
          Node *slow = head; 
          Node* fast = head->next; 
          
          bool flag = false; 
          while(fast != nullptr && slow != nullptr && fast->next!=nullptr){
              if(fast == slow)  {
                  flag = true; 
                  break; 
              }
              slow = slow->next; 
              fast = fast->next->next; 
          }
          
          if(!flag) return 0 ; 
          Node *temp = fast->next; 
          int len = 1; 
          
          while(temp != fast){
              len++;
              temp = temp->next; 
          }
          return len ;   
      }
  };