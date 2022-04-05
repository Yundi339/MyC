
class Solution {
public:
	int climbStairs(int n) {
		if (n == 1) return 1;
		int last_last = 1;
		int last = 2;
		int ans = last;
		for (size_t i = 2; i < n; i++)
		{
			ans = last_last + last;
			last_last = last;
			last = ans;
		}
		return ans;
	}
};



class Solution {
public:
	int climbStairs(int n) {
		vector<int> dp(n+1);
		dp[0] = 1;
		dp[1] = 2;
		for (size_t i = 2; i < n; i++)
		{
			dp[i] = dp[i-1] + dp[i - 2];
		}
		return dp[n - 1];
	}
};
