// Adding Ones

class Solution {
  public:
    vector<int> update(int n, vector<int>& updates) {
       vector<int> result(n); 
       
       for(int i = 0 ; i  < updates.size(); i++){
           result[updates[i]-1]++;
       }
       
       for(int i = 1 ; i< n; i++){
           result[i] += result[i - 1];
       }
       return result; 
      
    }
};