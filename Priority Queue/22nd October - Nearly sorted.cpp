// Nearly sorted/


class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
       int n = arr.size();
       
       priority_queue<int , vector<int>, greater<>>pq; 
       for(int i = 0 ; i  < k; i++){
           pq.push(arr[i]);
       }
       
       int i = k ; 
       while( i < n ){
           pq.push(arr[i]);
         
          arr[i - k ] = pq.top();
          pq.pop();
          i++;
       }
       
       while(!pq.empty()){
           arr[i - k ] = pq.top();
           pq.pop();
           i++;
       }
       
       
       
       
       
        
    }
};