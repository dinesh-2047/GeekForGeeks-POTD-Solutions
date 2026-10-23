// Trace Path


class Solution {
public:
    bool isPossible(int n, int m, string& s) {
        int i = 0, j = 0;
        int minI = 0, maxI = 0;
        int minJ = 0, maxJ = 0;

        for (char ch : s) {
            if (ch == 'L') {
                j--;
            } 
            else if (ch == 'R') {
                j++;
            } 
            else if (ch == 'D') {
                i--;
            } 
            else { 
                i++;
            }

            minI = min(minI, i);
            maxI = max(maxI, i);
            minJ = min(minJ, j);
            maxJ = max(maxJ, j);
        }

        return (maxI - minI < n && maxJ - minJ < m);
    }
};
