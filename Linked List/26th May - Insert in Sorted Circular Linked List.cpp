// Insert in Sorted Circular Linked List

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        
        //what if no node
        if(!head)
        {
            Node* t=new Node(data);
            t->next=t;
            return t;
        }
        Node* prev=head;
        Node* curr=head->next;
        
        
        // what if only one node
        if(prev==curr)
        {
            Node* t=new Node(data);
            prev->next=t;
            t->next=curr;
            return head;
        }
        
        // what if data is less than equal to our first element 
        //then without traversing the whole list i put head's value
        //in a new node after the head and replace head's value with data 
        
       
        
        if(data<=head->data)
        {
            Node* t=new Node(head->data);
            head->data=data;
            t->next=head->next;
            head->next=t;
            
            return head;
        }
        
        // to see if data belongs in a sandwich in the linked list
        
        while(curr!=head)
        {
            if(data>=prev->data&&data<=curr->data)
            {
                Node* t=new Node(data);
            prev->next=t;
            t->next=curr;
            return head;
                
            }
            prev=curr;
            curr=curr->next;
        }
        
        // now data is the greatest element of our array so placed 
        //just before the head
        Node* t=new Node(data);
            prev->next=t;
            t->next=curr;
            return head;
        
    }
};