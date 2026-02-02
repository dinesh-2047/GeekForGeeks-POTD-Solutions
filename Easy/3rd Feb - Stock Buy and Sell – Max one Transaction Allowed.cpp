// Stock Buy and Sell – Max one Transaction Allowed

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        int result = 0 ;
        int mini = prices[0];
        
        for(int i= 1 ; i < n; i++){
            result = max(result , prices[i] - mini);
            mini = min(mini , prices[i]);
        }
        return result; 
     
        
    }
};
