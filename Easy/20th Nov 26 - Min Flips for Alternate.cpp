// Min Flips for Alternate


class Solution {
public:
    int minFlips(string &s) {
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < s.size(); i++) {
            if (i % 2 == 0) {
                if (s[i] != '0') cnt1++;
                if (s[i] != '1') cnt2++;
            }
            else {
                if (s[i] != '1') cnt1++;
                if (s[i] != '0') cnt2++;
            }
        }

        return min(cnt1, cnt2);
    }
};
