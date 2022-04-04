class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<int> dp(n,1);
		for (int i = 0; i < m-1; i++)
		{
			for (int j = 1; j < n; j++)
			{
				dp[j] += dp[j - 1];
			}
		}
		return dp[n - 1];
	}
};