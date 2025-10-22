// K Closest Points to Origin


 using P =  pair<int , int> ;
class Solution {
  public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
         int n = points.size();
        priority_queue<P, vector<P>, greater<>>pq; 
        int x1 = 0 ; 
        int y1 = 0; 
        for(int i = 0 ; i < n ;i++){
            int x2 = points[i][0];
            int y2 = points[i][1];
            
            
            int distance = pow((x2 - x1), 2) + pow((y2 - y1), 2);
            
            pq.push({distance, i});
            
            
        }
        
        vector<vector<int>>result; 
        
        while(k--){
            auto curr = pq.top();
            pq.pop();
            
            result.push_back(points[curr.second]);
        }
        
        return result; 
    }
};