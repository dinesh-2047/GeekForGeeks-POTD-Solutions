// Maximum Without 3 Consecutive Set Bits

class Solution {
	public:
	int maxValue(int n) {
		string b = "" ;
		while (n) {
			b += to_string(n%2);
			n /= 2;
		}
		reverse(b.begin(), b.end());
		for (int i = 2; i < b.length(); i++) {
			if (b[i] == '1' && b[i - 1] == '1' && b[i - 2] == '1') {
				b[i] = '0';
			}
		}
		int result = 0 ;
		int p = 0 ;
		for (char c : b) {
			result = result * 2 + (c - '0');
		}
		
		return result;
		
	}
};
