
class Solution {
public:
    int minDiff(int k, vector<int> &arr) {
        int n = arr.size();

        if (k == 0) {
            return *max_element(arr.begin(), arr.end()) - *min_element(arr.begin(), arr.end());
        }

        vector<int> preMax(n), preMin(n);
        vector<int> sufMax(n), sufMin(n);

        preMax[0] = preMin[0] = arr[0];

        for (int i = 1; i < n; i++) {
            preMax[i] = max(preMax[i - 1], arr[i]);
            preMin[i] = min(preMin[i - 1], arr[i]);
        }

        sufMax[n - 1] = sufMin[n - 1] = arr[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            sufMax[i] = max(sufMax[i + 1], arr[i]);
            sufMin[i] = min(sufMin[i + 1], arr[i]);
        }

        int result = INT_MAX;

        for (int l = 0; l + k <= n; l++) {
            int r = l + k - 1;
            int mn = INT_MAX, mx = INT_MIN;

            if (l > 0) {
                mn = min(mn, preMin[l - 1]);
                mx = max(mx, preMax[l - 1]);
            }

            if (r + 1 < n) {
                mn = min(mn, sufMin[r + 1]);
                mx = max(mx, sufMax[r + 1]);
            }

            if (mn != INT_MAX) {
                result = min(result, mx - mn);
            }
        }

        return result;
    }
};
