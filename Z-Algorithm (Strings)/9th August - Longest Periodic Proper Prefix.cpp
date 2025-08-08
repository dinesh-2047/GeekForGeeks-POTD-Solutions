// Longest Periodic Proper Prefix

vector<int> zFunction(string &s) {
    int n = s.size();
    vector<int> z(n);
    
    // [l, r] is the current segment that matches a prefix
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) {
            // inside the z-box: reuse previously computed values
            z[i] = min(r - i + 1, z[i - l]);
        }
        // try to extend the match beyond the current z-box
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        // update the z-box if the match extended beyond
        // current right boundary
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}


int getLongestPrefix(string &s) {
    int n = s.size();
    vector<int> z = zFunction(s);

    // traverse z-array to find position where
    // suffix equals prefix
    for (int i = n - 1; i > 0; i--) {
        if (z[i] == n - i) {
            
            // s[i:] is a suffix that is equal to the 
            // prefix of length n - i
            return i;
        }
    }

    return -1;
}
