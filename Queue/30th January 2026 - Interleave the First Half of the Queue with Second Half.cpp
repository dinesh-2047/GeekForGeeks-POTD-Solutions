// Interleave the First Half of the Queue with Second Half


class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        queue<int>q2; 
        int n = q.size()/2;
        int Q = n; 
        while(Q--){
            q2.push(q.front());
            q.pop();
        }
        
   
        for(int i = 0 ; i < n; i++){
            cout<<q2.front()<<" "<< q.front()<<" "; 
            q2.pop();
            q.pop();
          
        }
        
    }
};