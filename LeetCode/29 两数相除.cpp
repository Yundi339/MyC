class Solution {
public:
	int divide(int dividend, int divisor) {
		if (dividend == 0) return 0;
		if (dividend == 1 || dividend == -1) {
			if (divisor == 1) return dividend;
			if (divisor == -1) return -dividend;
			else return 0;
		}
		if (divisor == 1 ) return dividend;
		if (dividend == INT_MIN) {
			if (divisor == 1) return INT_MIN;
			if (divisor == -1) return INT_MAX;
		}
		if (divisor == INT_MIN) return dividend == INT_MIN ? 1 : 0;

		int ans = 0;
		bool sign = true;
		if (divisor < 0) {
			sign = !sign;
			divisor = -divisor;
			
		}
		if (dividend<0) {
			sign = !sign;
			if (dividend == INT_MIN)
			{
				dividend += divisor;
				++ans;
			}
			dividend = -dividend;
		}
		int S = dividend;
		for (int i = 31; i >= 0; --i) {
			int T = S >> i;
			if (T >= divisor) {
				ans += (1 << i);
				S -= (divisor << i);
			}
		}
		return sign ? ans : -ans;

	}
};