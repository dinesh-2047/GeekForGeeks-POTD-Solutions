// Max Amount by Selling K Tickets


class Solution {
  public:
  int mod = 1e9  + 7 ;
    int maxAmount(vector<int>& arr, int k) {
       int n = arr.size();
       
       priority_queue<int> pq(begin(arr), end(arr));
       
       int cnt = 0 ; 
       int result = 0; 
       while (cnt < k && !pq.empty()) {
                int curr = pq.top();
                pq.pop();
            
                if (curr == 0) break;
            
                result = (result + curr) % mod;
            
                if (curr > 1)
                    pq.push(curr - 1);
            
                cnt++;
            }
       return result;
        
    }
};