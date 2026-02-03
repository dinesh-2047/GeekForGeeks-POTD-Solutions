// Last Moment Before All Ants Fall Out

class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int left_max = 0 ; 
        int right_max = 0 ; 
        
        for(auto &l : left){
            left_max = max(left_max, l);
        }
        
        for(auto &r : right){
            right_max = max(right_max, n- r);
        }
        
        return max(left_max, right_max);
        
    }
};