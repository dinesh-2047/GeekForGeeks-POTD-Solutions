// Number of distinct subsequences

class Solution {
  public:
  const int mod = 1e9+7;
    int distinctSubseq(string s) {
       unordered_map<char, int> lastOccurrence;
        long long count = 1; // Start with empty subsequence
        
        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];
            long long prevCount = count;
            
            // Double the count (each existing subsequence can include or exclude current char)
            count = (count * 2) % mod;
            
            // If character appeared before, subtract duplicates
            if(lastOccurrence.find(ch) != lastOccurrence.end()) {
                count = (count - lastOccurrence[ch] + mod) % mod;
            }
            
            // Update last occurrence count for this character
            lastOccurrence[ch] = prevCount;
        }
        
        return count;
    }
};