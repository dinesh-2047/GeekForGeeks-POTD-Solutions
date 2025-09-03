// Linked List Group Reverse



// Approach 1 -> using array 
class Solution {
  public:
  void reversee(vector<int> &vec, int i , int j ){
      reverse(begin(vec) + i , begin(vec) + j);
  }
  
  
    Node *reverseKGroup(Node *head, int k) {
        vector<int>vec; 
        Node* temp = head; 
        
        while(temp){
            vec.push_back(temp->data);
            temp = temp->next; 
            
        }
        int n = vec.size();
        
        int i =0 ; 
        while(i < n ){
            reversee(vec, i , min(i+ k, n));
            i+=k;
        }
        temp =  head; 
        
        for(int i = 0 ; i < n; i++){
            temp->data = vec[i];
            temp = temp->next; 
        }
        
        return head; 
        
    }
};









//Approach 2 ITERATIVE
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
 
    Node *reverseKGroup(Node *head, int k) {
      Node *curr = head; 
      Node* newHead = nullptr; 
      Node* tail = nullptr; 
      
      while(curr){
          Node* groupHead = curr ;
          Node* prev = nullptr ; 
          Node* next =nullptr;
          
          int count = 0 ; 
          while(curr && count < k ){
              next = curr->next; 
              curr->next = prev ; 
              prev = curr; 
              curr = next; 
              count++;
          }
          
          if(!newHead) newHead = prev;
          
          if(tail) tail->next = prev; 
          
          tail = groupHead; 
          
          
      }
      return newHead; 
        
    }
};






//Approach 3 Recursion 
class Solution {
  public:
 
    Node *reverseKGroup(Node *head, int k) {
     Node* curr = head; 
     Node* prev = nullptr; 
     Node* next = nullptr; 
     
     int count = 0 ; 
     while(curr && count < k){
         count++;
         curr = curr->next; 
     }
     
     if(count > 0){
         int c = 0 ; 
         curr = head; 
         
         while(curr && c < count){
             next = curr->next; 
             curr->next = prev; 
             prev = curr; 
             curr = next; 
             
             c++;
         }
         
         if(next){
             head->next = reverseKGroup(next, k);
         }
         return prev ; 
     }
     return head; 
     
        
    }
};