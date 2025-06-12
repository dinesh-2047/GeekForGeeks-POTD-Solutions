// Koko Eating Bananas


class Solution {
  public:
  bool isPossible(int mid , int k, int cumSum, vector<int>& arr){
     int count = 0 ; 
     int n= arr.size();
     for(int i = 0 ; i <n; i++){
         if(arr[i] <= mid){
             count++;
         }
         else{
             count= count + ceil((double)arr[i]/mid);
         }
     }
     if(count <= k) return true; 
     else return false;
  }
  
    int kokoEat(vector<int>& arr, int k) {
       
        int n = arr.size();
        
        int cumSum = 0 ; 
        for(int i = 0 ; i <n; i++){
            cumSum += arr[i];
        }
        
        int low = 1 ; 
        int high = *max_element(arr.begin(), arr.end());
        int result  = high ; 
        
        while(low <= high){
            int mid = low + (high - low )/2;
            
            if(isPossible(mid, k, cumSum, arr)){
                result = min(result , mid);
                high = mid - 1;
            }
            else low = mid + 1; 
        }
        
         return result; 
        
    }
};