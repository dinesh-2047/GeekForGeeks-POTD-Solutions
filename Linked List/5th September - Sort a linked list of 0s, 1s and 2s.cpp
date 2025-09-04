// Sort a linked list of 0s, 1s and 2s



// Approach 1 using vector 
class Solution {
  public:
    Node* segregate(Node* head) {
        Node *temp = head; 
        
        vector<int>vec; 
        while(temp){
            vec.push_back(temp->data);
            temp = temp ->next; 
        }
        
        sort(begin(vec), end(vec));
        
        temp = head; 
        int i =0 ; 
        while(temp){
            temp->data = vec[i++];
            temp = temp->next; 
         }
         return head; 
        
    }
};








//Approach 2 using count of 0s, 1s and 2s
/* Node is defined as
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
    Node* segregate(Node* head) {
       Node* temp = head; 
       int zero_cnt = 0 ; 
       int one_cnt = 0 ; 
       int two_cnt = 0 ; 
       
       while(temp){
           if(temp->data == 0) zero_cnt++;
           else if(temp->data == 1) one_cnt++;
           else two_cnt++;
           temp = temp->next; 
       }
        temp = head; 
       while(zero_cnt || one_cnt || two_cnt){
           if(zero_cnt){
               temp->data = 0;
               zero_cnt--;
           }
           else if(one_cnt){
               temp->data = 1; 
               one_cnt--;
           }
           else{
             
              temp->data = 2 ; 
              two_cnt--;
           }
           temp = temp->next; 
       }
       return head; 
        
    }
};