// MAX DAG Edges

class Solution {

  public:

    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {

        // code here

        int E = edges.size();

        int totalPossible = V * (V -1) /2;

        

        return totalPossible - E;

    }

};