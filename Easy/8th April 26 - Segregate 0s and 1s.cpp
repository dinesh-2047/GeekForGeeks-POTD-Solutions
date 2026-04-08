// Segregate 0s and 1s

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int n = arr.size();
        
        int i = 0 ; 
        int j = n-1 ; 
        
        while( i <= j ){
           if(arr[i] == 0) i++;
           else if(arr[j] == 1) j--;
           else {
               swap(arr[i], arr[j]);
               i++;
               j--;
           }
        }
        
        
    }
};
