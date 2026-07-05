// Max Sum Path in Two Arrays

class Solution {
  public:
    int maxPathSum(vector<int> &a, vector<int> &b) {
        int n = a.size();
        int m = b.size();
        
       int result = 0 ; 
        int i = 0 ; 
        int j = 0 ; 
        
        int sum1 = 0 ; 
        int sum2 = 0 ; 
        
        while(i < n || j < m ){
            if(i == n) {
                sum2 += b[j];
                j++;
                continue; 
            }
            
            if(j==m){
                sum1 += a[i];
                i++;
                continue; 
            }
            
            if(a[i] == b[j]){
                result += max(sum1, sum2) + a[i];
                sum1 = 0 ; 
                sum2 = 0 ; 
                i++;
                j++;
            }
            else if(a[i] > b[j]){
                sum2 += b[j];
                j++;
            }
            else {
                sum1 += a[i];
                i++;
            }
        }
        return  result + max(sum1 , sum2);
    }
};
