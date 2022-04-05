class Solution {
public:
	int mySqrt(int x) {
        if(x==0) return 0;
		int left = 1;
		int right = x;
		while (left <= right) {
			long mid = ((right - left) >> 1) + left;
			if (mid * mid == x) return mid;
			if (mid * mid > x) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		return right;
	}
};