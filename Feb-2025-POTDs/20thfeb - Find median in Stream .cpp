// Find median in stream 

//  approache using priortiy queue with diff types of coding style 


// code 1 
class Solution {
    public:
      vector<double> getMedian(vector<int> &arr) {
          vector<double>ans;
          
          int n = arr.size();
      
          
          priority_queue<int>left_max_heap;
          priority_queue<int , vector<int>, greater<>>right_min_heap; 
          
         for(int i = 0 ; i<n; i++){
             if(left_max_heap.empty() || arr[i] < left_max_heap.top()){
                 left_max_heap.push(arr[i]);
             }
             else{
                 right_min_heap.push(arr[i]);
             }
             
             if(left_max_heap.size() > right_min_heap.size() + 1) {
                 right_min_heap.push(left_max_heap.top());
                 left_max_heap.pop();
             }
             else if(left_max_heap.size() < right_min_heap.size()){
                 left_max_heap.push(right_min_heap.top());
                 right_min_heap.pop();
             }
             
             
             if(left_max_heap.size() == right_min_heap.size()){
                 double mean = (left_max_heap.top() + right_min_heap.top())/2.0;
                 ans.push_back(mean);
                 
             }
             else{
                 ans.push_back(left_max_heap.top());
             }
             
         }
         
         return ans; 
          
          
      }
  };



//   code 2

class Solution {
    public:
      vector<double> getMedian(vector<int> &arr) {
          vector<double>ans;
          
          int n = arr.size();
      
          
          priority_queue<int>left_max_heap;
          priority_queue<int , vector<int>, greater<>>right_min_heap; 
          
         for(int i = 0 ; i<n; i++){
             if(left_max_heap.empty() || arr[i] < left_max_heap.top()){
                 left_max_heap.push(arr[i]);
             }
             else{
                 right_min_heap.push(arr[i]);
             }
             
             if(abs((int)left_max_heap.size() -(int) right_min_heap.size()) > 1) {
                 right_min_heap.push(left_max_heap.top());
                 left_max_heap.pop();
             }
             else if(left_max_heap.size() < right_min_heap.size()){
                 left_max_heap.push(right_min_heap.top());
                 right_min_heap.pop();
             }
             
             
             if(left_max_heap.size() == right_min_heap.size()){
                 double mean = (left_max_heap.top() + right_min_heap.top())/2.0;
                 ans.push_back(mean);
                 
             }
             else{
                 ans.push_back(left_max_heap.top());
             }
             
         }
         
         return ans; 
          
          
      }
  };


//   code 3 

class Solution {
    public:
      vector<double> getMedian(vector<int> &arr) {
          int n = arr.size();
          
          vector<double>ans;
          
          priority_queue<int>maxHeap;
          priority_queue<int , vector<int>, greater<>>minHeap; 
          
          for(int i = 0 ; i<n; i++){
              if(maxHeap.empty() || arr[i] < maxHeap.top()){
                  maxHeap.push(arr[i]);
              }
              else{
                  minHeap.push(arr[i]);
              }
              
              if(maxHeap.size() > minHeap.size() + 1){
                  minHeap.push(maxHeap.top());
                  maxHeap.pop();
              }
              else if(maxHeap.size() < minHeap.size()){
                  maxHeap.push(minHeap.top());
                  minHeap.pop();
              }
              
              if(maxHeap.size() == minHeap.size()){
                  double mean = (maxHeap.top() + minHeap.top())/2.0;
                  ans.push_back(mean);
              }
              else{
                  ans.push_back(maxHeap.top());
              }
          }
          return ans; 
      }
  };