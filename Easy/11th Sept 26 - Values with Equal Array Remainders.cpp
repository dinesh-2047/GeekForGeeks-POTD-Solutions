// Values with Equal Array Remainders

class Solution {
public:
    int sameMod(vector<int> &arr) {
        int n = arr.size();
        int g = 0;

        for (int i = 1; i < n; i++) {
            g = gcd(g, abs(arr[i] - arr[0]));
        }

        if (g == 0)
            return -1;

        int result = 0;

        for (int i = 1; i * i <= g; i++) {
            if (g % i == 0) {
                result++;

                if (i != g / i)
                    result++;
            }
        }

        return result;
    }
};