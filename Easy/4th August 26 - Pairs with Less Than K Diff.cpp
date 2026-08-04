// Pairs with Less Than K Diff



class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
       int n = arr.size();
       
       sort(begin(arr), end(arr));
    
       int result = 0 ;
       
      int i =0 ; 
      for(int j = i + 1; j < n; j++){
          if(arr[j] - arr[i] < k ){
              result += j - i;
          }
          else {
              i++;
              j--;
          }
      }
      return result;
        
    }
};


