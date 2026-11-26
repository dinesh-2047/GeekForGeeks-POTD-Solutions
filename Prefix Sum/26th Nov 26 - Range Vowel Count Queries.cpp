// Range Vowel Count Queries


class Solution {
public:
    vector<int> countVowels(string &s, vector<vector<int>> &queries) {
        int n = s.size();
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i];

            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
                s[i] == 'o' || s[i] == 'u') {
                prefix[i + 1]++;
            }
        }

        vector<int> result;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            result.push_back(prefix[r + 1] - prefix[l]);
        }

        return result;
    }
};
