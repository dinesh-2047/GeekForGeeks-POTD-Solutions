// Minimum Squares with Full Cuts

class Solution {
	public:
	int minSquares(int n, int m) {
		int result = 0;
		
		while (n > 0 && m > 0) {
			if (n < m) {
				swap(n, m);
			}
			
			result += n / m;
			n %= m;
		}
		
		return result;
		
	}
};
