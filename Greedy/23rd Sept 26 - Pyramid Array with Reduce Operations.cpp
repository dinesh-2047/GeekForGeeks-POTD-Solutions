// Pyramid Array with Reduce Operations

class Solution {
	public:
	int formPyramid(vector<int>& arr) {
	    int n= arr.size();
		vector<int> left(n), right(n);
		
		left[0] = min(arr[0], 1);
		
		for (int i = 1; i < n; i++) 
			left[i] = min(arr[i], left[i - 1] + 1);
		
		
		right[n - 1] = min(arr[n - 1], 1);
		
		for (int i = n - 2; i >= 0; i--) 
			right[i] = min(arr[i], right[i + 1] + 1);
		
		
		int maxPeak = 0;
		
		for (int i = 0; i < n; i++) 
			maxPeak = max(maxPeak, min(left[i], right[i]));
		
		
		long long total = 0;
		
		for (int x : arr) {
			total += x;
		}
		
		return total - 1LL * maxPeak * maxPeak;
	}
};
