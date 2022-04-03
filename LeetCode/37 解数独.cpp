class Solution {
private:
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
	string str_board;
	bitset<81> row, col, grid;


public:
	void solveSudoku(vector<vector<char>>& board) {
		std::function<bool(int,int)> DFS =[&](int count, int index)->bool {
			--count;
			while (index < 81 && str_board[index] != '.') {
				index++;
			}
			for (int num = 0; num < 9; ++num) {
				int r = *(row_map + index) + num;
				int c = *(col_map + index) + num;
				int g = *(grid_map + index) + num;
				if (!row[r] && !col[c] && !grid[g]) {
					str_board[index] = num + '1';
					row[r] = col[c] = grid[g] = 1;
					if (count == 0 || DFS(count, index + 1)) {
						board[index / 9][index % 9] = str_board[index];
						return true;
					}
					row[r] = col[c] = grid[g] = 0;
					str_board[index] = '.';
				}
			}
			return false;
		};
		int count = 81;
		int index = 0;
		for (vector<char>& c_board : board) {
			for (char& c : c_board) {
				str_board += c;
				if (c != '.') {
					count--;
					size_t num = c - 49;
					row[row_map[index] + num] = col[col_map[index] + num] = grid[grid_map[index] + num] = true;
				}
				++index;
			}
		}
		DFS(count, 0);
	}
};

/*
vector<vector<char>> board = {
	{'5','3','.','.','7','.','.','.','.'},
	{'6','.','.','1','9','5','.','.','.'},
	{'.','9','8','.','.','.','.','6','.'},
	{'8','.','.','.','6','.','.','.','3'},
	{'4','.','.','8','.','3','.','.','1'},
	{'7','.','.','.','2','.','.','.','6'},
	{'.','6','.','.','.','.','2','8','.'},
	{'.','.','.','4','1','9','.','.','5'},
	{'.','.','.','.','8','.','.','7','9'} 
};
solution.solveSudoku(board);
*/