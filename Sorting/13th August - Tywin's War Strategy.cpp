// Tywin's War Strategy


class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        
        int n = arr.size();
        vector<int>howMuch(n, 0);
        
        for(int i = 0 ;i < n; i++){
            int rem = arr[i]%k;
            int toAdd = (k - rem ) %k;
            howMuch[i] = toAdd;
        }
        
        sort(howMuch.begin(), howMuch.end());
        
      
        int soldiers = 0 ; 
        
        for(int i = 0 ;i < (n+1)/2; i++){
            soldiers+=howMuch[i];
        }
        return soldiers; 
        
        
    }
};