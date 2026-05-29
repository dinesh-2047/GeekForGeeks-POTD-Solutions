// Replace with XOR of Adjacent


class Solution {
  public:
    void replaceElements(vector<int>& arr) {
       int n = arr.size();
       
       int prev = arr[0];
       
       arr[0] = arr[0] ^arr[1];
       
       for(int i = 1; i  < n - 1; i++){
           int val = prev ^ arr[i + 1];
           prev = arr[i];
           arr[i] = val; 
       }
       arr[n- 1] = arr[n - 1] ^ prev; 
        
    }
};