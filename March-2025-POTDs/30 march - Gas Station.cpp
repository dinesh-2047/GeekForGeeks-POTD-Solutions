// Gas Station

// Approach -> Greedy
class Solution {
    public:
      int startStation(vector<int> &gas, vector<int> &cost) {
          int n = gas.size();
          int totalkamai = accumulate(gas.begin(), gas.end(), 0);
          int totalkharcha = accumulate(cost.begin(), cost.end(), 0);
          
          if(totalkamai < totalkharcha) return -1;
          int total = 0; 
          int result = 0 ; 
          for(int i = 0 ; i<n; i++){
             
              total = total + gas[i] - cost[i];
              
              if(total < 0 ){
                  total = 0 ; 
                  result = i+1; 
              }
          }
          return result; 
          
      }
  };