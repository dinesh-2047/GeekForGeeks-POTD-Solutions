// Dominant Pairs

class Solution {
public:
    int dominantPairs(vector<int>& arr) {
        int n = arr.size();
        int mid = n / 2;

        vector<int> first(arr.begin(), arr.begin() + mid);
        vector<int> second(arr.begin() + mid, arr.end());

        sort(first.begin(), first.end());
        sort(second.begin(), second.end());

        long long ans = 0;
        int j = 0;

        for (int i = 0; i < mid; i++) {
            while (j < mid && first[i] >= 5LL * second[j]) {
                j++;
            }

            ans += j;
        }

        return ans;
    }
};