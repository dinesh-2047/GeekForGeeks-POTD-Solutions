// Missing in Array 

// Approach 1 
class Solution {
    public:
      int missingNum(vector<int>& arr) {
        int n = arr.size() + 1;
  int expectedSum = (1LL * n * (n + 1)) / 2;
  int actualSum = accumulate(arr.begin(), arr.end(), 0LL);
  return expectedSum - actualSum;
  
          
      }
  };



// Approach 2 
class Solution {
    public:
      int missingNum(vector<int>& arr) {
          int n =arr.size();
          
          sort(arr.begin(),arr.end());
         
          for(int i=0;i<n;i++){
              if(i!=arr[i]-1) return arr[i]-1;
              
          }
          return n+1;
          
      }
  };