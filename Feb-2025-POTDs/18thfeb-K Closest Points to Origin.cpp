// K Closest Points to Origin

class Solution {
    public:
      vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
         priority_queue<pair<int, int> ,vector<pair<int, int>>, greater<>>pq;
         for(int i = 0; i < points.size(); i++){
             int sq = pow(points[i][0],2) + pow( points[i][1],2);
           
             pq.push({sq,i});
         }
         
         vector<vector<int>>result; 
         for(int i =0; i<k; i++){
             auto top= pq.top();
             pq.pop();
             
             
             int idx=top.second;
             result.push_back(points[idx]);
             
         }
         return result; 
         
      }
  };