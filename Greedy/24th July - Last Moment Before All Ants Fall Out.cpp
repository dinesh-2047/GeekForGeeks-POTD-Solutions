// Last Moment Before All Ants Fall Out



class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
       int leftMax = 0 ; 
       int rightMax = 0 ; 
       
       for(auto &l : left){
           leftMax = max(leftMax, l);
       }
       
       for(auto &r : right){
           rightMax = max(rightMax,n- r);
       }
       
       return max(leftMax, rightMax);
    }
};