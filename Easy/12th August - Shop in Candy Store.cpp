// Shop in Candy Store


class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
      
        int n = prices.size();
        
        sort(prices.begin(), prices.end());
        
        int i = 0 ; 
        int j= n-1; 
        
        int mini = 0 ; 
        while(i<=j){
            mini += prices[i];
            int kk = k ; 
            while(kk > 0 ){
                j--;
                kk--;
            }
            i++;
        }
        
        int maxi = 0 ; 
        i = 0 ; 
        j = n-1; 
          while(i<=j){
            maxi += prices[j];
            int kk = k ; 
            while(kk > 0 ){
                i++;
                kk--;
            }
          j--;;
        }
        
        return {mini, maxi};
    }
};