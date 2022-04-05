class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		matrix.shrink_to_fit();
		int row = matrix.size();
		int col = matrix[0].size();
		vector<bool> map(col);
		for (int i = 0; i < row; i++) {
			bool flag = false;
			for (int j = 0; j < col; j++) {
				if (matrix[i][j] == 0) {
					flag = true;
					map[j] = true;
				}
			}
			if (flag) {
				matrix[i].assign(col, 0);
		        matrix[i].shrink_to_fit();
			}
		}
		for (int j = 0; j < col; j++) {
			if (map[j]) {
				for (int i = 0; i < row; i++) {
					matrix[i][j] = 0;
				}
			}
		}
	}
};