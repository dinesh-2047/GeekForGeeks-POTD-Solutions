// Minimum time to fulfil all orders


class Solution {
  public:
    int donutsByChef(int t, int r) {
        double D = 1.0 + 8.0 * t / r;
        return int((-1.0 + sqrt(D)) / 2.0);
    }
    bool canMake(vector<int>& ranks, int n, int t) {
        int total = 0;
        for (int r : ranks) {
            total += donutsByChef(t, r);
            if (total >= n)
                return true;
        }
        return false;
    }
    int minTime(vector<int>& ranks, int n) {
        int rmin = *min_element(ranks.begin(), ranks.end());
        int r = rmin * n * (n + 1) / 2;
        int l = 0, result = r;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (canMake(ranks, n, mid)) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }
};