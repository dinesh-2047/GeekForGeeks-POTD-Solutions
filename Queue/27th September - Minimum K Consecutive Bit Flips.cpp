// Minimum K Consecutive Bit Flips


class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
         int n = arr.size();
        int flips = 0;
        int flipped = 0;
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (!q.empty() && q.front() == i) {
                q.pop();
                flipped ^= 1;
            }

            if ((arr[i] ^ flipped) == 0) {
                if (i + k > n) return -1;

                flips++;
                q.push(i + k);
                flipped ^= 1;
            }
        }
        return flips;
        
    }
};