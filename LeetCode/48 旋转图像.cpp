class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		// 先翻转再对称
		reverse(matrix.begin(), matrix.end());
		size_t n = matrix.size();
		for (size_t i = 0; i < n; i++)
			for (size_t j = i; j < n; j++)
				swap(matrix[i][j], matrix[j][i]);
	}
};
