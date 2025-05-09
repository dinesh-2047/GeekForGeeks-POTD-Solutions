// Longest Subarray with Majority Greater than K


class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
       unordered_map<int, int> firstSeen; // Stores first index where a prefix sum was seen
    int prefixSum = 0, maxLen = 0;

    for (int i = 0; i < arr.size(); i++) {
        // Convert the value based on condition
        if (arr[i] > k)
            prefixSum += 1;
        else
            prefixSum -= 1;

        // If prefix sum is positive, entire subarray from 0 to i is valid
        if (prefixSum > 0) {
            maxLen = i + 1;
        }
        else {
            // If prefixSum - 1 was seen before, subarray from that index+1 to i is valid
            if (firstSeen.count(prefixSum - 1)) {
                maxLen = max(maxLen, i - firstSeen[prefixSum - 1]);
            }
        }

        // Store the first occurrence of this prefix sum
        if (!firstSeen.count(prefixSum)) {
            firstSeen[prefixSum] = i;
        }
    }

    return maxLen;
        
    }
};