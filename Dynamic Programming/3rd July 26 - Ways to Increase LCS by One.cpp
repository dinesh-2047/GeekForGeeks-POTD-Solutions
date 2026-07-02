// Ways to Increase LCS by One

class Solution {
public:
    int n1, n2;
    vector<vector<int>> dpPref, dpSuff;

    int pref(int i, int j, string &s1, string &s2) {
        if (i == 0 || j == 0) return 0;

        int &result = dpPref[i][j];
        if (result != -1) return result;

        if (s1[i - 1] == s2[j - 1])
            result = 1 + pref(i - 1, j - 1, s1, s2);
        else
            result = max(pref(i - 1, j, s1, s2),
                         pref(i, j - 1, s1, s2));

        return result;
    }

    int suff(int i, int j, string &s1, string &s2) {
        if (i == n1 || j == n2) return 0;

        int &result = dpSuff[i][j];
        if (result != -1) return result;

        if (s1[i] == s2[j])
            result = 1 + suff(i + 1, j + 1, s1, s2);
        else
            result = max(suff(i + 1, j, s1, s2),
                         suff(i, j + 1, s1, s2));

        return result;
    }

    int waysToIncreaseLCSBy1(string &s1, string &s2) {
        n1 = s1.size();
        n2 = s2.size();

        dpPref.assign(n1 + 1, vector<int>(n2 + 1, -1));
        dpSuff.assign(n1 + 1, vector<int>(n2 + 1, -1));

        int L = pref(n1, n2, s1, s2);
        int result = 0;

        for (int pos = 0; pos <= n1; pos++) {
            bool seen[26] = {0};

            for (int j = 0; j < n2; j++) {
                char c = s2[j];

                if (seen[c - 'a']) continue;

                if (pref(pos, j, s1, s2) + 1 + suff(pos, j + 1, s1, s2) == L + 1) {
                    result++;
                    seen[c - 'a'] = true;
                }
            }
        }

        return result;
    }
};