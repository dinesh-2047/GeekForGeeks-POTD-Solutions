// Minimum Cost of ropes

class Solution {
  public:
    int minCost(vector<int>& arr) {
       int n = arr.size();
       
       priority_queue<int , vector<int>, greater<>>pq(begin(arr), end(arr)); 
       int result = 0  ; 
       while(!pq.empty()){
           if(pq.size() == 1){
               break; 
           }
           int first = pq.top();
           pq.pop();
           int second = pq.top();
           pq.pop();
           
           result += first +second; 
           pq.push(first + second);
       }
       return result; 
        
    }
};