// Equalize the Towers

class Solution {
  public:
  long long findCost(vector<int> &heights , vector<int> &cost, int target){
      long long c= 0 ; 
      int n = heights.size();
      for(int i = 0 ; i <n; i++){
          c+= abs(heights[i] - target) * cost[i];
      }
      return c; 
  }
  
    int minCost(vector<int>& heights, vector<int>& cost) {
        int n = heights.size();
        
         long long result = LLONG_MAX;
         
         int st = *min_element(begin(heights), end(heights));
         int end = *max_element(heights.begin(), heights.end());
         
         while(st<=end){
             int mid = st + (end -st)/2;
             
             long long cost1 = findCost(heights , cost , mid);
             long long cost2 = findCost(heights, cost , mid+1);
             
             result = min(cost1 , cost2);
             if(cost1 < cost2) end = mid -1; 
             else st = mid + 1; 
         }
         return (int) result; 
        
    }
};