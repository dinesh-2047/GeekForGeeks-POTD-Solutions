// Sum of Beauty of All Substrings

class Solution {
public:
    int beautySum(string& s) {
        int result = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mp;

            for (int j = i; j < n; j++) {
                mp[s[j]]++;

                int maxi = 0, mini = n;

                for (auto it : mp) {
                    maxi = max(maxi, it.second);
                    mini = min(mini, it.second);
                }

                result += (maxi - mini);
            }
        }

        return result;
    }
};