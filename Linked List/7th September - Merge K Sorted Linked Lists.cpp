// Merge K Sorted Linked Lists 

// Approach 1 : Using sorting 
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
    Node* mergeKLists(vector<Node*>& arr) {
        Node *head = new Node(-1);
        
        int n = arr.size();
        
        vector<int>vec;
        for(Node* a : arr){
            Node *temp = a; 
            while(temp){
                vec.push_back(temp->data);
                temp = temp->next; 
            }
            
            
        }
        sort(begin(vec), end(vec));
         Node* temp = head; 
        for(int i = 0 ; i < vec.size() ; i++){
            temp->next = new Node(vec[i]);
            temp = temp->next; 
        }
        return head->next;
     }
};






//Approach 2 : Using priority queue
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
    Node* mergeKLists(vector<Node*>& arr) {
        Node *head = new Node(-1);
        priority_queue<int , vector<int >, greater<>>pq; 
        
        int n = arr.size();
        
        for(Node* a : arr){
            Node *temp = a; 
            while(temp){
                pq.push(temp->data);
                temp = temp->next; 
            }
            
            
        }
        
        Node *temp = head; 
        while(!pq.empty()){
            temp->next = new Node(pq.top());
            pq.pop();
            temp = temp->next; 
        }
        return head->next; 
        
        
        
     }
};