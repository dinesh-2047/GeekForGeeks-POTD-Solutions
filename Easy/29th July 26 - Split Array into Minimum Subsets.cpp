// Split Array into Minimum Subsets

class Solution {
  public:
    int minSubsets(vector<int>& arr) {
       int n = arr.size();
       
       sort(begin(arr), end(arr));
       
       int result = 1; 
       
       for(int i = 1;  i  < n; i++){
           if(arr[i]-arr[i- 1] != 1){
               result++;
           }
       }
       return result;
        
    }
};
