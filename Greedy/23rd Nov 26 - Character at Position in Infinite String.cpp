// Character at Position in Infinite String


class Solution {
public:
    char posInfinite(string &s, int pos) {
        vector<long long> len;
        len.push_back(s.size());

        long long n = s.size();
        int i = 1;

        while (n < pos) {
            n = 2 * n + i;
            len.push_back(n);
            i++;
        }

        while (len.size() > 1) {
            long long prev = len[len.size() - 2];
            long long curr = len.back();

            long long middle = prev + (len.size() - 1);

            if (pos <= prev) {
                len.pop_back();
            }
            else if (pos <= middle) {
                return '$';
            }
            else {
                pos = curr - pos + 1;
                len.pop_back();
            }
        }

        return s[pos - 1];
    }
};