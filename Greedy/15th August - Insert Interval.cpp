// Insert Interval


class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        
        
        int n = intervals.size();
        
        vector<vector<int>>result; 
        int newSt = newInterval[0];
        int newEnd = newInterval[1];
        
        int i = 0 ; 
        
        while( i < n && intervals[i][1] < newSt ){
            result.push_back(intervals[i]);
            i++;
        }
        
        while(i < n && intervals[i][0] <= newEnd){
            newSt = min(intervals[i][0], newSt);
            newEnd = max(intervals[i][1], newEnd);
            i++;
        }
        result.push_back({newSt, newEnd});
        while(i < n ){
            result.push_back(intervals[i]);
        i++;
        }
        return result; 
        
    }
};