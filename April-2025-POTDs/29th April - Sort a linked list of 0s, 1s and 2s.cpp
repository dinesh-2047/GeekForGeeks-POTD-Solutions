// Sort a linked list of 0s, 1s and 2s


class Solution {
    public:
      // Function to sort a linked list of 0s, 1s and 2s.
      Node* segregate(Node* head) {
          int countZero = 0 ; 
          int countOnes = 0 ; 
          int countTwos = 0;
          
          
          Node* temp = head; 
          
          while(temp){
              if(temp->data == 0) countZero++; 
              if(temp->data == 1) countOnes++; 
              if(temp->data == 2) countTwos++; 
              temp = temp->next; 
          }
          
         temp = head; 
         
         while(countZero){
             temp->data = 0;
             countZero--;
             temp = temp->next; 
         }
         
         while(countOnes){
             temp->data =1;
             countOnes--;
             temp= temp -> next; 
         }
         
         while(countTwos){
             temp->data = 2;
             countTwos--;
             temp= temp->next; 
         }
         
         return head; 
          
      }
  };