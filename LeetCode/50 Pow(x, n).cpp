class Solution {
public:
	double myPow(double x, int n) {
		double ans = 1;
		bool flag = (n >= 0);
		while (n != 0) {
			if (n & 1)
				ans = ans*x;
			x = x * x;
			n /= 2;
		}
		return flag ? ans : 1 / ans;
	}
};