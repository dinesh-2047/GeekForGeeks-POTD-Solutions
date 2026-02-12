// Max min Height


class Solution {
  public:
  bool isPossible(vector<int> &arr, int k , int w , int mid){
      vector<int>vec =arr; 
      int n = arr.size();
      for(int i= 0 ; i <n; i++){
          if(vec[i] < mid){
              int temp = mid - vec[i];
              if(temp >k) return false; 
              k-=temp; 
              vec[i] = mid; 
              
              for(int j = i + 1; j <n && j < i+w; j++){
                  vec[j] += temp ; 
              }
          }
          
      }
      return true; 
  }
  
  
    int maxMinHeight(vector<int> &arr, int k, int w) {
        int n = arr.size();
        
        
        int st = *min_element(begin(arr), end(arr));
        int end = st  + k; 
        
        int result = 0 ; 
        
        while(st <= end){
            int mid = st + (end - st)/2;
            
            if(isPossible(arr, k , w , mid)){
                result = mid; 
                st = mid + 1;
            }
            else end = mid -1 ; 
        }
        return result; 
    }
};