// Intersection of Two Sorted Arrays


class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        
        vector<int>result; 
        
        int i = 0 ; 
        int j = 0 ; 
        
        
        while( i < n && j < m ){
            if(a[i] < b[j]){
                i++;
            }
            else if(a[i] > b[j]){
                j++;
            }
            else {
                if(result.empty() || (!result.empty() && result.back() != a[i]))
                result.push_back(a[i]);
                i++;
                j++;
            }
        }
        
        
       return result; 
      
        
    }
};