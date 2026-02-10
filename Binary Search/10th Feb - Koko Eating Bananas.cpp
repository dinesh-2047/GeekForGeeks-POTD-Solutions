// Koko Eating Bananas

class Solution {
  public:
  int n ; 
  bool isPossible(vector<int> &arr, int &k , int mid){
      int h = 0 ; 
      for(int i = 0 ; i < n; i++){
          h += ceil((double)arr[i]/mid);
      }
      return h<=k; 
  }
  
    int kokoEat(vector<int>& arr, int k) {
         n = arr.size();
        
        int l = 1 ; 
        int r = *max_element(begin(arr), end(arr));
        int result = r ; 
        
        while(l <= r){
            int mid = l + (r-l)/2; 
            if(isPossible(arr, k , mid)){
                result = mid ; 
                r = mid -1; 
            }
            else l = mid + 1; 
        }
        return result; 
    }
};