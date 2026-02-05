// Maximize Number of 1's


class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        int n = arr.size();
        
        int i = 0 ; 
        int j = 0; 

        int count0 = 0 ; 
        int result = 0 ; 
        
        while( j < n ){
            if(arr[j] == 0 )count0++;
            
            while(i <= j && count0 > k){
                if(arr[i] == 0) count0--;
                i++;
            }
            result = max(result, j-i+1);
            j++;
        }
        return result; 
        
    }
};
