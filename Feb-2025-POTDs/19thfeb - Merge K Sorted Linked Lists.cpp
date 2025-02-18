// MERge K sorted linked list 

/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

// Approach 1 

class Solution {
    public:
      Node* mergeKLists(vector<Node*>& arr) {
          vector<int> num; // Store all values from the lists
  
          // Extract all elements from all linked lists
          for (int i = 0; i < arr.size(); i++) {
              Node* temp = arr[i]; // Start from the head of each list
              while (temp) {
                  num.push_back(temp->data); // Store node value
                  temp = temp->next; // Move to next node
              }
          }
  
          // If there are no elements, return NULL
          if (num.empty()) return NULL;
  
          // Sort the collected numbers
          sort(num.begin(), num.end());
  
          // Create new sorted linked list
          Node* head = new Node(num[0]);
          Node* tail = head;
          for (int i = 1; i < num.size(); i++) {
              Node* temp = new Node(num[i]);
              tail->next = temp;
              tail = tail->next;
          }
  
          return head;
      }
  };





class Solution {
    public:
      Node* mergeKLists(vector<Node*>& arr) {
          priority_queue<int, vector<int>, greater<int>>pq; 
          
          for(int i = 0 ; i<arr.size(); i++){
              Node* curr =  arr[i];
              
              while(curr){
                  pq.push(curr->data);
                  curr = curr -> next; 
              }
          }
          
          Node* head = new Node (pq.top());
          pq.pop();
          Node* tail = head; 
          
          while(!pq.empty()){
              auto node = pq.top();
              pq.pop();
              
              Node* temp = new Node(node);
              tail->next = temp ;
              tail = tail->next; 
          }
          return head; 
      }
  };