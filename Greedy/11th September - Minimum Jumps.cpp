// Minimum Jumps


class Solution {
  public:
 
    int minJumps(vector<int>& arr) {
       int n = arr.size();
       if(arr[0] == 0 ) return -1; 
       if(n < 2  ) return 0; 
       
       int far = 0 ; 
       int jump = 0 ; 
       int r = 0 ; 
       
       for(int i = 0 ; i < n ; i++){
           far = max(far, i +arr[i]);
           
           if(i == r){
               jump++;
               r = far;
               if(r >= (n-1)) return jump ; 
           }
       }
       return -1; 
        
    }
};
