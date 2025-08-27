// Maximize Number of 1's


class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        int n = arr.size();
        
        int i = 0 ; 
        int j = 0 ; 
        int result = 0 ; 
        int zero_count = 0 ;
        while (j < n ){
            if(arr[j]==0) zero_count++;
            if(zero_count > k ){
               
                    if(arr[i] == 0 ) zero_count--;
                    i++;
                
            }
            
            result = max(result , j - i + 1);
            j++;
        }
        return result; 
    }
};
