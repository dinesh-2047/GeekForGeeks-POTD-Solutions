// Gas Station


// Approach 1 
class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
       int n = gas.size();
       
       int totalgas = accumulate(begin(gas), end(gas), 0);
       int need = accumulate(begin(cost), end(cost), 0);
       
       if(totalgas < need) return -1; 
       
       int curr = 0 ; 
       int result = 0 ; 
       for(int i = 0 ;  i < n; i++){
           curr += gas[i] - cost[i];
           
           if(curr < 0 ){
               curr = 0; 
               result = i + 1; 
           }
       }
       return result; 
    }
};



//Approach 2
class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
       int n = gas.size();
       
       int totalgas = 0 ; 
       int currgas = 0 ; 
       
       int result = 0 ; 
       for(int i = 0 ; i < n; i++){
           totalgas += gas[i] - cost[i];
           currgas += gas[i] - cost[i];
           
           if(currgas < 0){
               currgas = 0 ; 
               result = i + 1;
           }
           
       }
       if(totalgas < 0) return -1; 
       return result ;
    }
};