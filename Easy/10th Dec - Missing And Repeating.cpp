// Missing And Repeating

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        
        int m ,r; 
        m = r = -1; 
        
        for(int i = 0 ; i < n; i++){
            int val = abs(arr[i]); 
            if(arr[val - 1] > 0 ){
                arr[val - 1] = -arr[val-1];
            }
            else r = val; 
        }
        
        for(int i = 0 ; i  < n; i++){
            if(arr[i] > 0 ){
                  m = i + 1; 
                  break; 
            }
        }
        return {r, m};
    }
};