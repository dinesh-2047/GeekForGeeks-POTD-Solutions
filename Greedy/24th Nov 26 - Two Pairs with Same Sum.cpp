// Two Pairs with Same Sum


class Solution {
  public:
    vector<int> findPairs(vector<int>& arr) {
        // code here

        int n = arr.size();
        unordered_map<long long, pair<int, int>> mp;
        vector<int> result = {-1, -1, -1, -1};

        for (int i = 0; i < n; i++) {
            for (int j = i +1; j < n; j++) {
                long long sum = arr[i] + arr[j];

                if (mp.count(sum)) {
                    auto [a, b] = mp[sum];

                    if (a != i && a != j && b != i && b != j) {
                        vector<int>temp = {a, b, i, j};

                        if (result[0] == -1 || temp < result) {
                            result = temp;
                        }
                    }
                } else {
                    mp[sum] = {i, j};
                }
            }
        }

        return result;

    }
};