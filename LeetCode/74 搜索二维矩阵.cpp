class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int row = matrix.size();
		int col = matrix[0].size();
		int i = 0;
		while (i < row - 1 && matrix[i + 1][0] <= target) {
			i++;
		}
		for (int j = 0; j < col && target >= matrix[i][j]; j++) {
			if (target == matrix[i][j])
				return true;
		}
		return false;
	}
};