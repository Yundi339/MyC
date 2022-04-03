class Solution {	
public:
	void solveSudoku(vector<vector<char>>& board) {
		const int grid_map[81] = {
			   0,0,0,    9,9,9, 18,18,18,
			   0,0,0,    9,9,9, 18,18,18,
			   0,0,0,    9,9,9, 18,18,18,
			27,27,27, 36,36,36, 45,45,45,
			27,27,27, 36,36,36, 45,45,45,
			27,27,27, 36,36,36, 45,45,45,
			54,54,54, 63,63,63, 72,72,72,
			54,54,54, 63,63,63, 72,72,72,
			54,54,54, 63,63,63, 72,72,72,
		};
		const int row_map[81] = {
			 0, 0, 0, 0, 0, 0, 0, 0, 0,
			 9, 9, 9, 9, 9, 9, 9, 9, 9,
			18,18,18,18,18,18,18,18,18,
			27,27,27,27,27,27,27,27,27,
			36,36,36,36,36,36,36,36,36,
			45,45,45,45,45,45,45,45,45,
			54,54,54,54,54,54,54,54,54,
			63,63,63,63,63,63,63,63,63,
			72,72,72,72,72,72,72,72,72,
		};
		const int col_map[81] = {
			0,9,18,27,36,45,54,63,72,
			0,9,18,27,36,45,54,63,72,
			0,9,18,27,36,45,54,63,72,
			0,9,18,27,36,45,54,63,72,
			0,9,18,27,36,45,54,63,72,
			0,9,18,27,36,45,54,63,72,
			0,9,18,27,36,45,54,63,72,
			0,9,18,27,36,45,54,63,72,
			0,9,18,27,36,45,54,63,72,
		};
		bitset<81> row, col, grid;
		vector<int> v;
		v.reserve(64);
		std::function<bool(int)> DFS =[&](int vi)->bool {
			if (vi >= v.size()) return false;
			int index = v[vi];
			int i = index / 9;
			int j = index % 9;
			for (int num = 0; num < 9; ++num) {
				int r = *(row_map + index) + num;
				int c = *(col_map + index) + num;
				int g = *(grid_map + index) + num;
				if (!row[r] && !col[c] && !grid[g]) {
					board[i][j] = num + 49;
					row[r] = col[c] = grid[g] = 1;
					if (vi + 1 == v.size() || DFS(vi + 1)) {
						return true;
					}
					row[r] = col[c] = grid[g] = 0;
				}
			}
			return false;
		};

		int count = 0;
		int index = 0;
		for (vector<char>& c_board : board) {
			for (char& c : c_board) {
				if (c != '.') {
					size_t num = c - 49;
					row[row_map[index] + num] = col[col_map[index] + num] = grid[grid_map[index] + num] = true;
				}
				else {
					v.push_back(index);
				}
				++index;
			}
		}
		DFS(0);
	}
};