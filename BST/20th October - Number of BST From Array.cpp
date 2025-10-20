// Number of BST From Array


class Solution{
public:    

vector<int> computeFact(int num) {
    vector<int> fact(num + 1);
    fact[0] = 1;
    for (int i = 1; i <= num; i++)
        fact[i] = fact[i - 1] * i;
    return fact;
}

// Compute nth Catalan number using precomputed factorials
int catalan(int n, vector<int>& fact) {
    return fact[2 * n] / (fact[n] * fact[n + 1]);
}

// Function to count number of BSTs for each element as root
vector<int> countBSTs(vector<int>& arr) {

    int n = arr.size();
    vector<vector<int>> sorted;

    // Pair each element with its index and sort by value
    for (int i = 0; i < n; i++)
        sorted.push_back({arr[i], i});
    sort(sorted.begin(), sorted.end());

    // Precompute factorials up to 2*n
    vector<int> fact = computeFact(2 * n);

    vector<int> numBSTs(n);

    // Compute BST count for each element as root
    for (int i = 0; i < n; i++) {
        int j = sorted[i][1];
        numBSTs[j] = catalan(i, fact) * catalan(n - i - 1, fact);
    }

    return numBSTs;
}
};
