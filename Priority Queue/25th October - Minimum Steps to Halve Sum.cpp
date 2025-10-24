// Minimum Steps to Halve Sum


// Approach 1 
class Solution {
  public:
    int minOperations(vector<int>& arr) {
        int n = arr.size();
        
        priority_queue<double>pq; 
        
        double sum = 0 ; 
        for(auto &num : arr){
            sum += num; 
            pq.push(num);
        }
        
        double target = sum/2.0;
         int op = 0 ; 
        while(sum > target){
            auto curr = pq.top();
            pq.pop();
            double half = curr/2; 
            
            sum -= curr; 
            sum += half; 
            
            op++;
            pq.push(half);
        }
        return op ; 
        
    }
};



