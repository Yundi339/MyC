class Solution {
public:
	vector<vector<bool>> map;
	int row, col;
	int Where(int& x, int& y, int mode) {
		// 右
		if (mode == 1) {
			// 下
			if (y + 1 == col || map[x][y + 1]) {
				x++;
				return 2;
			}
			else {
				y++;
				return 1;
			}
		}// 下
		else if (mode == 2) {
			// 左
			if (x + 1 == row || map[x+1][y]) {
				y--;
				return 3;
			}
			else {
				x++;
				return 2;
			}
		}// 左
		else if (mode == 3) {
			// 上
			if (y - 1 < 0 || map[x][y-1]) {
				x--;
				return 4;
			}
			else {
				y--;
				return 3;
			}
		}// 上
		else {
			// 右
			if (x - 1 < 0 || map[x-1][y]) {
				y++;
				return 1;
			}
			else {
				x--;
				return 4;
			}
		}
		return 0;
	}
	vector<int> spiralOrder(const vector<vector<int>>& matrix) {
		row = matrix.size();
		col = matrix[0].size();
		map = vector<vector<bool>>(row, vector<bool>(col));
		int count = 0;
		int x = 0, y = 0;
		int mode = 1;

		int sum = row * col;
		vector<int> ans(sum);
		while (count < sum) {
			map[x][y] = true;
			ans[count] = matrix[x][y];
			mode = Where(x, y,mode);
			count++;
		}
		return ans;
	}
};