// Not a subset sum

class Solution {
  public:
    int findSmallest(vector<int> &arr) {
        int n = arr.size();
        sort(begin(arr), end(arr));
        int result = 1 ; 
        for(int i = 0 ;i  < n; i++){
            
            if(arr[i] > result) {
                break; 
            }
            result  += arr[i];
            
        }
        return result; 
    }
};