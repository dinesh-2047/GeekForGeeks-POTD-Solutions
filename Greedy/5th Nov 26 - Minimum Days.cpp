// Minimum Days

class Solution {
public:
    int getMinimumDays(string &s, vector<int> &p) {

        int n = s.size();

        int low = 0, high = n;
        int result = n;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            vector<bool> removed(n, false);

            for (int i = 0; i < mid; i++) {
                removed[p[i]] = true;
            }

            bool valid = true;

            for (int i = 0; i < n - 1; i++) {

                if (!removed[i] && !removed[i + 1] &&
                    s[i] == s[i + 1]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                result = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return result;
    }
};