// Optimal File Merge

class Solution {
  public:
    int minComputation(vector<int> &files) {
        int n = files.size();
        
        priority_queue<int, vector<int>, greater<>>pq(begin(files), end(files)); 
        int result = 0 ; 
        while( pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            
            int y = pq.top();
            pq.pop();
            
            pq.push(x+ y );
            result += x + y ; 
        }
        
        return result;
        
    }
};