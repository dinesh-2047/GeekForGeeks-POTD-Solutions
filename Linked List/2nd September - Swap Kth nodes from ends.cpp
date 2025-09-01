// Swap Kth nodes from ends



// Approach 1 using vector 
class Solution {
  public:
    Node* swapKth(Node* head, int k) {
       vector<int>vec; 
       Node* temp = head; 
       while(temp){
           vec.push_back(temp->data);
           temp = temp->next;
       }
       
       int n = vec.size();
       if(n < k  ) return head; 
       
       swap(vec[k-1], vec[n-k]);
       
       int i = 0 ;
       temp = head; 
       while(temp){
           if(temp->data != vec[i]){
               temp->data = vec[i];
           }
           i++;
           temp = temp->next; 
       }
       return head  ; 
        
    }
};




//approach 2 
class Solution {
  public:
  int getLen(Node* head){
      Node *temp = head; 
      int len = 0 ; 
      while(temp){
          len++;
          temp = temp->next; 
      }
      return len ; 
  }
  
    Node* swapKth(Node* head, int k) {
      int len = getLen(head); 
      
    
      int posVal1 = k-1 ; 
      int posVal2 = len - k ; 
      
      int val1 = 0 ; 
      int val2 = 0 ; 
      
      Node* temp = head;
      int count = 0 ; 
      while(temp){
          if(count == posVal1  ){
              val1 = temp->data;
          }
          if(count == posVal2){
              val2 = temp->data;
              
          }
          count++;
          temp = temp->next;
      }
      
      count = 0 ; 
      temp = head; 
      while(temp){
          if(count == posVal1  ){
              temp->data = val2; 
          }
          if(count == posVal2){
             temp->data = val1; 
              
          }
          count++;
          temp = temp->next;
      }
      
       return head; 
        
    }
};