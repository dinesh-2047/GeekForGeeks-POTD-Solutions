// Longest Matching in Dictionary with Removals

class Solution {
public:
    string result;
    string findLongestWord(string &s, vector<string> &d) {
        int n = s.length();

        vector<vector<int>> pos(26);

        for (int i = 0; i < n; i++) {
            pos[s[i] - 'a'].push_back(i);
        }

        for (auto &t : d) {
            int prev = -1;
            bool possible = true;

            for (char c : t) {
                auto &v = pos[c - 'a'];

                auto it = upper_bound(v.begin(), v.end(), prev);

                if (it == v.end()) {
                    possible = false;
                    break;
                }

                prev = *it;
            }

            if (possible) {
                if (t.length() > result.length() ||
                    (t.length() == result.length() && t < result)) {
                    result = t;
                }
            }
        }

        return result;
    }
};