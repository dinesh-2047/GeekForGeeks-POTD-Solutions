// Coin Piles

class Solution {
  public:
    int minimumCoins(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<int>prefix_sum(n,0);
        prefix_sum[0]=arr[0];
        
        for(int i=1;i<n;i++)
        prefix_sum[i]=prefix_sum[i-1]+arr[i];
        
        int ans=INT_MAX;
        int prev=0;
        
        for(int i=0;i<n;i++)
        {
            int index=upper_bound(arr.begin()+i,arr.end(),arr[i]+k)-arr.begin() ;
            if(i>0 && arr[i]!=arr[i-1])
            prev=prefix_sum[i-1];
            
            ans=min(ans,prev+prefix_sum[n-1]-prefix_sum[index-1]-(n-index)*(arr[i]+k));
        }
        
        return ans ;
        
        
    }
};
