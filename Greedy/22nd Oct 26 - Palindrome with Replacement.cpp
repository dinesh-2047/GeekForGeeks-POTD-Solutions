// Palindrome with Replacement/


class Solution {
public:
    int minimumSum(string &s) {
        int n = s.length();

        int i = 0;
        int j = n - 1;

        while(i < j) {
            if(s[i] != '?' && s[j] != '?' && s[i] != s[j])
                return -1;

            i++;
            j--;
        }

        i = 0;
        j = n - 1;

        while(i < j) {
            if(s[i] == '?' && s[j] != '?')
                s[i] = s[j];
            else if(s[j] == '?' && s[i] != '?')
                s[j] = s[i];

            i++;
            j--;
        }

        i = 0;

        while(i < n) {
            if(s[i] != '?') {
                i++;
                continue;
            }

            int j = i;

            while(j < n && s[j] == '?')
                j++;

            char ch = 'a';

            if(i > 0)
                ch = s[i - 1];
            else if(j < n)
                ch = s[j];

            for(int k = i; k < j; k++)
                s[k] = ch;

            i = j;
        }

        int result = 0;

        for(int i = 0; i < n - 1; i++)
            result += abs(s[i] - s[i + 1]);

        return result;
    }
};