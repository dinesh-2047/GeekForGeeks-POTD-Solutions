// Nth in Concatenated Decimal String


class Solution {
  public:
    char nthCharacter(int n) {
        long long digits = 1;
        long long count = 9;
        long long start = 1;

        while (n > digits * count) {
            n -= digits * count;
            digits++;
            count *= 10;
            start *= 10;
        }

        start += (n - 1) / digits;

        string num = to_string(start);
        return num[(n - 1) % digits];
    }
};
