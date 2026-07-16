// Max Absolute Diff of Two Subarrays

class Solution {
public:
    int maxDiffSubArrays(vector<int>& arr) {
        int n = arr.size();

        vector<int> leftMax(n), leftMin(n);
        vector<int> rightMax(n), rightMin(n);

    
        int curr = arr[0];
        leftMax[0] = arr[0];
        for (int i = 1; i < n; i++) {
            curr = max(arr[i], curr + arr[i]);
            leftMax[i] = max(leftMax[i - 1], curr);
        }

   
        curr = arr[0];
        leftMin[0] = arr[0];
        for (int i = 1; i < n; i++) {
            curr = min(arr[i], curr + arr[i]);
            leftMin[i] = min(leftMin[i - 1], curr);
        }


        curr = arr[n - 1];
        rightMax[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            curr = max(arr[i], curr + arr[i]);
            rightMax[i] = max(rightMax[i + 1], curr);
        }

      
        curr = arr[n - 1];
        rightMin[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            curr = min(arr[i], curr + arr[i]);
            rightMin[i] = min(rightMin[i + 1], curr);
        }

        int ans = 0;

        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, abs(leftMax[i] - rightMin[i + 1]));
            ans = max(ans, abs(leftMin[i] - rightMax[i + 1]));
        }

        return ans;
    }
};

