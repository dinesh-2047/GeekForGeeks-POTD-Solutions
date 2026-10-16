// Convert One String to Another with Constraints


class Solution {
public:
    bool isItPossible(string &s1, string &s2) {
        int n = s1.length();
        int m = s2.length();

        if (n != m) return false;

        int i = 0, j = 0;

        while (i < n && j < m) {
            while (i < n && s1[i] == '#') i++;
            while (j < m && s2[j] == '#') j++;

            if (i == n || j == m) {
                return i == n && j == m;
            }

            if (s1[i] != s2[j]) return false;

            if (s1[i] == 'A' && i < j) return false;
            if (s1[i] == 'B' && i > j) return false;

            i++;
            j++;
        }

        return true;
    }
};
