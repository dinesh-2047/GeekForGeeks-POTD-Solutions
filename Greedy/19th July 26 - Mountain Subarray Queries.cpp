// Mountain Subarray Queries

class Solution {
  public:
    vector<bool> processQueries(vector<int> &arr, vector<vector<int>> &queries) {
        int n = arr.size();
        int q = queries.size();
        vector<bool> result; 
        
        vector<int>l(n , 0);
        int mxl = 0 ; 
        for(int i = 1; i  < n; i++){
            if(arr[i] > arr[i - 1]){
                
                mxl = i ; 
            }
                l[i] = mxl ;
            
        }
        
        int mxr = n - 1; 
        vector<int> r(n , n - 1);
        for(int i = n-2; i >= 0 ; i--){
            if(arr[i] > arr[i + 1]){
                mxr = i ; 
            }
                r[i] = mxr; 
            
        }
        for(auto &q : queries){
            int ll = q[0];
            int rr = q[1];
            if(r[ll] >= l[rr]){
                result.push_back(true);
            }
            else result.push_back(false);
        }
        return result; 
    }
};