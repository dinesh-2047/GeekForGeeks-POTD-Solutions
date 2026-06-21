// Maximum Area Between Bars

class Solution {
  public:
    int maxArea(vector<int> &height) {
        int n = height.size();
        
        int result = 0 ;
        int i = 0 ; 
        int j = n-1 ; 
        
        while(i < j){
            result = max(result, min(height[i], height[j]) * (j-i-1));
            if(height[i] >= height[j]){
                j--;
            }
            else i++;
        }
        return result; 
        
    }
};