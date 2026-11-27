// Count Edges in Graph

class Solution {
  public:
    int countEdges(vector<vector<int>> &adj) {
        int result = 0 ;
        for(auto &nbr : adj){
            result += nbr.size();
        }
        return result/2; 
        
    }
};