class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size(); // 高
		int n = grid[0].size(); //宽
		vector<int> dp(n, 0);
		dp[0] += grid[0][0];
		for (int j = 1; j < n; j++) {
			dp[j] =  dp[j - 1] + grid[0][j];
		}
		for (int i = 1; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (j == 0) dp[j] += grid[i][j];
				else dp[j] = min(dp[j] + grid[i][j], dp[j - 1] + grid[i][j]);
			}
		}
		return dp[n - 1];
	}
};