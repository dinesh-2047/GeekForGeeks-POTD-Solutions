// Count Pairs Divisible By K


class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
       int n = arr.size();
       
       int result = 0 ; 
       vector<int> rem(k);
       
       
       for(int i= 0 ; i < n; i++){
           int r = arr[i]%k; 
           int sec = (k-r)%k; 
           result += rem[sec];
           rem[r]++;
       }
       return result;
        
    }
};