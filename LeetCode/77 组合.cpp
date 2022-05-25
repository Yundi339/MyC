class Solution {
public:
	void dfs(vector<vector<int>>& ans, vector<int>& temp, int level, int n, int k, int count) {
		if (count == k) {
			ans.push_back(temp);
			return;
		}
		for (int i = level; i <= n; i++) {
			temp[count] = i;
			count++;
			dfs(ans, temp, i + 1, n, k, count);
			count--;
		}

	}	
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> ans;
		vector<int> temp(k, 0);
		dfs(ans, temp, 1, n, k, 0);
		return ans;
	}
};