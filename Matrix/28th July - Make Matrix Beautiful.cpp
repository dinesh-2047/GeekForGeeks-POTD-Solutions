// Make Matrix Beautiful

Approach 1 -> O(n^2) and O(n)

#define all(x) begin(x), end(x)
class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        
        int n = mat.size();
        
        vector<int>rowSum(n);
        vector<int>colSum(n);
        
        for(int row = 0 ; row < n; row++){
            for(int col = 0 ; col < n; col++){
                rowSum[row] += mat[row][col];
            }
        }
        
        for(int col = 0 ; col < n ;col++){
            for(int row = 0 ; row < n; row++){
                colSum[col]+= mat[row][col];
            }
        }
        
        int requiredSum = max(*max_element(all(rowSum)), *max_element(all(colSum)));
        
        int result = 0; 
        
        for(int row = 0 ; row < n; row++){
            for(int col = 0 ; col < n; col++){
                int x = requiredSum - max(rowSum[row], colSum[col]);
                result+=x;
                rowSum[row] += x; 
                colSum[col] +=x;
            }
        }
         
        return result ; 
        
    }
};





Approach 2 -> Since n<= 900 
so O(n^2) and O(1) approach is , just use fixed size array 
#define all(x) begin(x), end(x)
class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        
        int n = mat.size();
        
        vector<int>rowSum(901);
        vector<int>colSum(901);
        
        for(int row = 0 ; row < n; row++){
            for(int col = 0 ; col < n; col++){
                rowSum[row] += mat[row][col];
            }
        }
        
        for(int col = 0 ; col < n ;col++){
            for(int row = 0 ; row < n; row++){
                colSum[col]+= mat[row][col];
            }
        }
        
        int requiredSum = max(*max_element(all(rowSum)), *max_element(all(colSum)));
        
        int result = 0; 
        
        for(int row = 0 ; row < n; row++){
            for(int col = 0 ; col < n; col++){
                int x = requiredSum - max(rowSum[row], colSum[col]);
                result+=x;
                rowSum[row] += x; 
                colSum[col] +=x;
            }
        }
         
        return result ; 
        
    }
};






Approach 3 -> wihout extra array 
class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        
        int n = mat.size();
        
        int maxSum =0 ; 
        
        for(int row = 0 ; row < n; row++){
            int sum = 0 ; 
            for(int col = 0 ; col < n; col++){
                sum+= mat[row][col];
            }
            maxSum = max(sum , maxSum );
            
        }
        
        for(int col = 0 ; col < n ;col++){
            int sum = 0;
            for(int row = 0 ; row < n; row++){
                sum+= mat[row][col];
            }
             maxSum = max(sum , maxSum );
        }
        
       
        
        int result = 0; 
        
        for(int row = 0 ; row < n; row++){
            int sum = 0 ;
            for(int col = 0 ; col < n; col++){
                sum+=mat[row][col];
            }
            result += (maxSum - sum);
        }
         
        return result ; 
        
    }
};






