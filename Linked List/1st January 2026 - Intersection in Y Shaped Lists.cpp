// Intersection in Y Shaped Lists


/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        Node *tempA = head1; 
        Node *tempB = head2; 
        
        while(tempA != tempB){
            if(tempA == nullptr){
                tempA = head1; 
            }
            else tempA = tempA->next; 
            
            if(tempB == nullptr){
                tempB = head2; 
            }
            else tempB = tempB->next;
        }
        return tempA; 
        
    }
};