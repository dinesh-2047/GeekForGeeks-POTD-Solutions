// Median in a row-wise sorted Matrix




// Approach 1 
class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int m = mat.size();
        int n = mat[0].size();
        
        vector<int>vec; 
        for(int i = 0 ; i  <m; i++){
            for(int j = 0 ; j < n; j++){
                vec.push_back(mat[i][j]);
            }
        }
        sort(begin(vec), end(vec));
        return vec[vec.size()/2];
    }
};




//Approach 2 

class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int m = mat.size();
        int n  = mat[0].size();
        
        priority_queue<vector<int>, vector<vector<int>>, greater<>>pq; 
        
        int midIndex = (m*n)/2; 
        
        int count = 0 ; 
        for(int i = 0 ; i < m ;i++){
            pq.push({mat[i][0], i , 0});
        }
        int result = 0 ; 
        while(count <= midIndex){
            auto curr = pq.top();
            pq.pop();
            int value = curr[0];
            int row = curr[1];
            int col = curr[2];
            count++;
             result = value; 
            
            if(col + 1 < n ){
                pq.push({mat[row][col + 1],row , col+1});
            }
        }
        return result; 
        
    }
};





//Approach 3 
class Solution {
  public:
  bool countLessThanMid(vector<vector<int>> &mat, int midIndex, int mid){
      int m = mat.size();
      int count = 0 ; 
      for(int i = 0; i < m; i++){
          count += upper_bound(begin(mat[i]), end(mat[i]), mid) - begin(mat[i]);
      }
      
      return count>=midIndex+1; 
  }
  
  
    int median(vector<vector<int>> &mat) {
         
         int m = mat.size();
         int n = mat[0].size();
         
         
         int midIdx = (m * n )/2; 
         
         int mini= INT_MAX;
         int maxi = INT_MIN;
         
         for(int i = 0 ; i < m; i++){
             mini = min(mini  , mat[i][0]);
             maxi = max(maxi , mat[i][n-1]);
         }
         
         int l = mini ; 
         int r = maxi;
         int result = 0 ; 
         
         
         while(l <= r){
             int mid = l + (r- l)/2; 
             
             if(countLessThanMid(mat , midIdx, mid)){
                    result = mid ; 
                 r = mid - 1; 
             }
             else{
               
                l = mid + 1 ;
                 
             }
         }
         return result; 
         
         
        
    }
};
