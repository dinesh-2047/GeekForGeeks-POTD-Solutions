// Kth element in Matrix



//Approach 1 using priority queue
class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int n = matrix.size();
        
        priority_queue<int , vector<int>, greater<>>pq; 
        
        for(int i = 0 ;i<n; i++){
            for(int j = 0 ; j<n; j++){
                pq.push(matrix[i][j]);
            }
        }
        
        while(k>1){
            pq.pop();
            k--;
        }
        
        return pq.top();
        
    }
};





//Approach 2 using binary search 
class Solution {
public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];
        int ans = -1 ; 

        while (low <= high) {
            int mid = low +  (high - low)/2;
            int count = 0;
            for (int i = 0; i < n; i++)
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();

            if (count >= k){
                ans = mid ; 
               high = mid -1; 
            }
            else
                low = mid + 1;
        }

        return ans; 
    }
};
