// Subset Sum on Generated Sequence

class Solution {
  public:
  using ll = long long ; 
    bool isPossible(vector<int>& arr, int s, int x) {
        int n = arr.size();
        vector<ll> pages(n + 1, 0);
        
        pages[0] = s; 
        
        ll sum = s; 
        
        for(int i = 0 ; i  < n; i++){
            pages[i + 1] = sum + arr[i];
            if(pages[i + 1] > x)
                break; 
                sum += pages[i + 1];
            
        }
        
        int i = n; 
        
        while(i >= 0 && x > 0){
            if(x >= pages[i])
            x -= pages[i];
            i--;
        }
        
        return x == 0 ; 

        
    }
};