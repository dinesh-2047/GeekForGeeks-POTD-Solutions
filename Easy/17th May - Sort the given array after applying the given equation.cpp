// Sort the given array after applying the given equation

// Approach 1 -> using sorting 
class Solution {
  public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        int n= arr.size();
        
      for(int i = 0 ; i<n; i++){
          int x = arr[i];
          arr[i] = A*(x*x) + (B*x) + C;
      }
      
      sort(arr.begin(), arr.end());
      return arr; 
        
    }
};


// Approach  2 -> using priority queue 
class Solution {
  public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        int n= arr.size();
    
        priority_queue<int , vector<int>, greater<>>pq; 
      for(int i = 0 ; i<n; i++){
          int x = arr[i];
          arr[i] = A*(x*x) + (B*x) + C;
          pq.push(arr[i]);
      }
      int i = 0 ; 
     while(!pq.empty()){
         auto curr = pq.top();
         pq.pop();
         
         arr[i++] = curr; 
     }
      return arr; 
        
    }
};