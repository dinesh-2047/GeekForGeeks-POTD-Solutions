// Maximum sum Rectangle




// Approach 1 using prefix sum // TLE

class Solution {
  public:
  int getSum(int up , int left , int down , int right , vector<vector<int>> &prefixSum){
         int sum = prefixSum[down][right];
         
         if(left - 1 >= 0 ){
             sum -= prefixSum[down][left - 1];
         }
         
         if(up  - 1 >= 0 ){
             sum -= prefixSum[up - 1][right];
         }
         
         if(left-1 >= 0 && up - 1>=0 ){
             sum += prefixSum[up -1 ][left - 1];
         }
         return sum; 
  }
  
  
    int maxRectSum(vector<vector<int>> &mat) {
        int m = mat.size();
        
        int n = mat[0].size();
        int maxSum = INT_MIN;
        
        vector<vector<int>>prefixSum(m, vector<int>(n, 0));
        
        
        //row wise sum
        for(int i = 0 ; i < m; i++){
            for(int j = 0 ; j  < n;j++){
                prefixSum[i][j] = mat[i][j];
                if(j-1 >= 0 ){
                    prefixSum[i][j] += prefixSum[i][j-1];
                }
            }
        }
        
        //col wise sum 
        for(int j = 0 ; j < n; j++){
            for(int i = 0 ; i < m; i++){
                if(i-1 >= 0 ){
                    prefixSum[i][j] += prefixSum[i-1][j];
                }
            }
        }
        
        
      for(int up = 0 ; up < m; up++){
          for(int left = 0 ; left < n; left++){
              for(int down = up ; down < m ; down++){
                  for(int right = left ; right <n; right++){
                      
                      
                      int sum = getSum(up, left , down , right , prefixSum);
                      maxSum = max(maxSum , sum);
                  }
              }
          }
      }
      return maxSum ; 
        
    }
};











//Approach 2 using kadane algo 
class Solution {
  public:
    int maxRectSum(vector<vector<int>> &mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        
        int result = INT_MIN; 
        
        
        for(int left = 0 ; left  < n ; left++){
            vector<int>temp(m , 0);
            
            for(int right = left ; right  < n; right++){
                 
                 for(int row = 0 ; row < m; row++){
                     temp[row] += mat[row][right];
                 }
                 
                 
                 int currSum =temp[0];
                 int currMaxSum = temp[0];
                  
                  for(int i = 1; i < m;i++){
                      currSum = max(temp[i], currSum + temp[i]);
                      currMaxSum = max(currMaxSum , currSum);
                  }
                  
                  result = max(result , currMaxSum);
                 
            }
        }
        
        return result; 
        
    }
};
