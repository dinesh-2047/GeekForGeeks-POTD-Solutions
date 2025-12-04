// Walls Coloring II


class Solution {
    public:
   int minCost(vector<vector<int>>& costs) {

    int n = costs.size();
    int m = costs[0].size();

    // 1 color + multiple walls - impossible
    if (m == 1 && n > 1) return -1;

    // Track smallest, second smallest, and index of smallest in previous row
    int prevMin1 = INT_MAX, prevMin2 = INT_MAX, minIndex = -1;

    // First row: find min1, min2
    for (int j = 0; j < m; j++) {
        int val = costs[0][j];
        if (val < prevMin1) {
            prevMin2 = prevMin1;
            prevMin1 = val;
            minIndex = j;
        } else if (val < prevMin2) {
            prevMin2 = val;
        }
    }

    // Process next rows
    for (int i = 1; i < n; i++) {

        int currMin1 = INT_MAX, currMin2 = INT_MAX, currIndex = -1;

        for (int j = 0; j < m; j++) {
            
            // Can't use prevMin1 if same color as previous row
            int cost = costs[i][j] + (j == minIndex ? prevMin2 : prevMin1);

            // Update min1, min2 for this row
            if (cost < currMin1) {
                currMin2 = currMin1;
                currMin1 = cost;
                currIndex = j;
            } else if (cost < currMin2) {
                currMin2 = cost;
            }
        }

        // Move current -> previous
        prevMin1 = currMin1;
        prevMin2 = currMin2;
        minIndex = currIndex;
    }

    return prevMin1;
}
};