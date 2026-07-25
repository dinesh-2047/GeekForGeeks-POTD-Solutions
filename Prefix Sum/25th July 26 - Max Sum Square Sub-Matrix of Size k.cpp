// Max Sum Square Sub-Matrix of Size k

class Solution {
	public:
	int maximumSum(vector<vector<int>> & mat, int k) {
		
		int m = mat.size();
		int n = mat[0].size();
		
		vector<vector<int>> pref(m, vector<int>(n));
		
		for (int i = 0 ; i < n; i++) {
			for (int j = 0 ; j < n; j++) {
				pref[i][j] = mat[i][j];
				
				if (i - 1 >= 0) {
					pref[i][j] += pref[i - 1][j];
				}
				if (j - 1 >= 0) {
					pref[i][j] += pref[i][j - 1];
				}
				
				if (i - 1 >= 0 && j - 1 >= 0) {
					pref[i][j] -= pref[i - 1][j - 1];
				}
			}
		}
		int result = -1e9; 
		for (int i = 0; i <= m - k; i++) {
			for (int j = 0; j <= n - k; j++) {
				
				int r2 = i + k - 1;
				int c2 = j + k - 1;
				
				int sum = pref[r2][c2];
				
				if (i > 0)
					sum -= pref[i - 1][c2];
				
				if (j > 0)
					sum -= pref[r2][j - 1];
				
				if (i > 0 && j > 0)
					sum += pref[i - 1][j - 1];
			      result = max(result, sum)	;
			}
		}
		return result; 
		
	}
};
