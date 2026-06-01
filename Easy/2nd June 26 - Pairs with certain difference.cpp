// Pairs with certain difference


class Solution {
  public:
    int sumDiffPairs(vector<int>& arr, int k) {
        int n = arr.size();
        
        int result = 0 ; 
        
        sort(rbegin(arr), rend(arr));
        
        for(int i = 1 ; i  < n; i++){
            if(abs(arr[i] - arr[i - 1] ) < k ){
                result += arr[i];
                result += arr[i -  1];
                i++;
            }
        }
        return result; 
        
    }
};