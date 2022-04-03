class Solution {
public:
	bool isMatch(const string &s, const string &p) {
		vector<vector<bool>> dp(s.length()+1, vector<bool>(p.length()+1, false));
		dp[0][0] = 1;
		// 匹配*
		for (size_t i = 2; i <= p.length(); ++i) {
			if (p[i - 1] == '*') {
				dp[0][i] = dp[0][i - 2];
			}
		}			
		for (size_t i = 1; i <= s.length(); ++i) {
			for (size_t j = 1; j <= p.length(); ++j) {
				if (p[j - 1] == '*') {
					dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
				}
				else {
					dp[i][j] = dp[i - 1][j - 1] && (p[j - 1] == '.' || s[i - 1] == p[j - 1]);
				}
			}
		}
		return dp[s.length()][p.length()];
	}
};