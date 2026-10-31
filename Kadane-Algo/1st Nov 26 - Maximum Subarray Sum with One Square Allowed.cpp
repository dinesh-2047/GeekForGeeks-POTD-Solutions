// Maximum Subarray Sum with One Square Allowed

class Solution {
public:
    int maximumSubarray(vector<int>& arr) {
        int n = arr.size();

        int normal = arr[0];
        int squared = arr[0] * arr[0];

        int result = max(normal, squared);

        for (int i = 1; i < n; i++) {
            int x = arr[i];

            int prevNormal = normal;
            int prevSquared = squared;

            normal = max(x, prevNormal + x);

            squared = max({ x * x,prevSquared + x,prevNormal + x * x});

            result = max({result, normal, squared});
        }

        return result;
    }
};