// Happiest Triplet

class Solution {
  public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        int n= a.size();
        
        sort(begin(a), end(a));
        sort(begin(b), end(b));
        sort(begin(c), end(c));
        
         vector<int>result; 
         int diff = INT_MAX;
         int sum = INT_MAX ; 
         int i = 0; 
         int j = 0; 
         int k = 0; 
        
        
        while(i < n && j < n && k < n ){
            int x = a[i];
            int y = b[j];
            int z = c[k];
            
            int maxi = max({x, y , z});
            int mini = min({x, y , z});
            
            int d = maxi - mini; 
            int s = x + y + z; 
            
            if(d < diff){
                result = {x, y , z};
                diff = d; 
                sum = s; 
            }
             if(d == diff){
                if(s < sum){
                    sum = s; 
                    result = {x, y, z}; 
                }
            }
            
            if(mini == x) i++;
            else if(mini == y ) j++;
            else k++;
        }
        
        sort(rbegin(result), rend(result));
        return result; 
    }
};