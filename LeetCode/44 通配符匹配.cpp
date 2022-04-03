class Solution {
public:
	bool isMatch(string& s, string& p) {
		string _p = "";
		char* last = nullptr;
		for (char& c : p) {
			if (c != '*' || !last || c != *last) {
				_p += c;
				last = &c;
			}
		}
		vector<vector<bool>> dp(s.length() + 1, vector<bool>(_p.length() + 1, false));
		dp[0][0] = 1;
		for (size_t i = 1; i <= _p.length(); ++i) {
			if (_p[i - 1] == '*') {
				dp[0][i] = dp[0][i-1];
			}
		}
		for (size_t i = 1; i <= s.length(); ++i) {
			for (size_t j = 1; j <= _p.length(); ++j) {
				if (_p[j - 1] == '*') {
					dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);
				}
				else if (_p[j - 1] == '?' || s[i - 1] == _p[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
				}
			}
		}
		return dp[s.length()][_p.length()];
	}
};