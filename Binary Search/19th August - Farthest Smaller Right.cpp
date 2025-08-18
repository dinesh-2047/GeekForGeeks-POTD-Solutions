// Farthest Smaller Right


class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        int n = arr.size();
         
         vector<int>result(n, -1);
          vector<int>suff(n);
          suff[n-1] = arr[n-1];
          for(int i = n-2; i >= 0; i--){
              suff[i] = min(suff[i+1],arr[i] );
          }
          
        for(int i = 0 ; i  < n;i++){
              int idx = lower_bound(suff.begin()+i+1, suff.end(), arr[i])-suff.begin()-1; 
         
              if(arr[idx] < arr[i] && idx!=i ){
                  result[i] =idx;
              }
              else result[i] = -1; 
              
        }
        return result; 
        
    }
};