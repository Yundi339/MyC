class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		bitset<9> row[9];
		bitset<9> col[9];
		bitset<9> grid[3][3];
		for ( i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') {
					int num = board[i][j] - '1'; // int num = board[i][j] - 49;
					if (row[i][num] || col[j][num] || grid[i/3][j/3][num]) return false;
					row[i][num] = col[j][num] = grid[i / 3][j / 3][num] = true;
				}
			}
		}

		return true;
	}
};