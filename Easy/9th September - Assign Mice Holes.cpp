// Assign Mice Holes



class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
         int n = mices.size();
        sort(mices.begin(), mices.end());
        sort(holes.begin(), holes.end());
        
        int result = INT_MIN;
        
        for(int i = 0 ; i < n ;i++){
             result = max(result , abs(holes[i] - mices[i]));
             
        }
        return result; 
    }
};