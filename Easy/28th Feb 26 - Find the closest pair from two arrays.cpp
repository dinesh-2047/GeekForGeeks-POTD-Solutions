// Find the closest pair from two arrays

class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
       
       int n = arr1.size();
       int m = arr2.size();
       
       vector<int>result = {-1, -1};
       
       
       int i = 0 ; 
       int j = m-1; 
       
       int minDiff = INT_MAX; 
       
       while(i < n && j >= 0 ){
           int sum = arr1[i] + arr2[j];
           int diff  = abs(sum - x);
           
            if(diff == 0 ) return {arr1[i], arr2[j]};
           
           if(diff < minDiff){
               minDiff = diff; 
               result[0] = arr1[i];
               result[1] = arr2[j];
              
           }
           if(sum < x) i++;
           else j--;
       }
       return result;
       
       
    }
};