// Bus Conductor

class Solution {
  public:
    int findMoves(vector<int>& chairs, vector<int>& passengers) {
        int n = chairs.size();
        sort(begin(chairs),end(chairs));
        sort(begin(passengers),end(passengers));
        
        int result = 0;
        for(int i = 0; i < n; i++){
            result += abs(chairs[i]-passengers[i]);
        }
        return result;
        
    }
};