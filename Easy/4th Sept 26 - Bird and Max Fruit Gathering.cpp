// Bird and Max Fruit Gathering

class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        
        int n = arr.size();
        
        int i = 0 ; 
        int j = 0 ; 
        
        int result = 0 ; 
        
        int sum = 0 ; 
        bool c = true; 
        int count = 0;
        
        while(i < n && j < n ){
            sum += arr[j];
            count++;
            if(count > m ){
                sum -= arr[i];
                count--;
                i++;
            }
            result = max(result, sum);
            j++;
            if(j == n ){
                if(c) {
                    j = 0 ; 
                    c = false; 
                }
            }
        }
    
        
        return result; 
        
    }
};