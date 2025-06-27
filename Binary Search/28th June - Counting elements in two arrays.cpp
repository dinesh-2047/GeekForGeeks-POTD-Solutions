// Counting elements in two arrays



// Approach 1 Binary Search 
class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        vector<int> result;
        
       
        sort(b.begin(), b.end());
        
        for(int i = 0 ; i<n; i++){
            int st = 0 ; 
            int end = m-1; 
            
            int target = a[i];
            int value = 0 ; 
            
            while(st<=end){
                int mid = st + (end -st)/2;
                
                if(b[mid] <= target){
                    value = mid + 1 ; 
                    st = mid +1; 
                }
                else end = mid - 1;
            }
            result.push_back(value);
        }
        return result; 
        
    }
};












//Approach 2 STL
class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        vector<int> result(n);
        
       
        sort(b.begin(), b.end());
        
        for(int i = 0 ; i<n; i++){
            result[i] = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
        }
        return result; 
        
    }
};






