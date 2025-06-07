// Sum-string


class Solution {
public:
    string addStrings(string a, string b) {
        string res = "";
        int i = a.size() - 1, j = b.size() - 1, carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            res += (sum % 10) + '0';
            carry = sum / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool check(string s1, string s2, string &s, int pos) {
        if ((s1.size() > 1 && s1[0] == '0') || (s2.size() > 1 && s2[0] == '0'))
            return false;

        string sum = addStrings(s1, s2);
        if (s.substr(pos, sum.size()) != sum) return false;

        if (pos + sum.size() == s.size()) return true;

        return check(s2, sum, s, pos + sum.size());
    }

    bool isSumString(string &s) {
        int n = s.size();
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                string s1 = s.substr(0, i);
                string s2 = s.substr(i, j - i);
                if (check(s1, s2, s, j)) return true;
            }
        }
        return false;
    }
};
