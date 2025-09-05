// Find length of Loop


// Approach 1 
/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node *temp = head; 
        unordered_map<Node*, bool>mp ; 
        bool isLoop = false; 
        Node *loopStart = nullptr ;
        
        while(temp){
            if(mp[temp]){
                isLoop = true; 
                loopStart =temp ; 
                
                break; 
            }
            mp[temp] = true; 
            temp = temp->next; 
        }
        if(!isLoop) return 0 ;
        temp = loopStart->next;
        
        int len = 1 ; 
       
        while(temp){
            if(temp == loopStart){
                break; 
            }
            len++;
       
            temp = temp->next; 
        }
        return len ; 
    }
};








//Approach 2 
class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        
       Node* slow = head; 
       Node* fast = head->next; 
        bool isLoop = false; 
        Node *loopStart = nullptr ;
        
        while(slow && fast &&  fast->next ){
            if(slow == fast){
                isLoop = true; 
                loopStart = slow ; 
                break; 
            }
            slow = slow->next; 
            fast = fast->next->next; 
        }
        
        if(!isLoop) return 0 ;
        Node *temp = loopStart->next;
        
        int len = 1 ; 
       
        while(temp){
            if(temp == loopStart){
                break; 
            }
            len++;
       
            temp = temp->next; 
        }
        return len ; 
    }
};