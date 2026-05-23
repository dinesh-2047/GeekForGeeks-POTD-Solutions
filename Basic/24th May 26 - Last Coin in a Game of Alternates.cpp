// Last Coin in a Game of Alternates

class Solution {
  public:
    int coin(vector<int>& arr) {
        int n = arr.size();
        
        int i = 0 ; 
        int j = n - 1; 
        
        while(i < j ){
            if(arr[j] > arr[i]){
                j--;
            }
            else i++;
        }
        
        return arr[i];
        
    }
};