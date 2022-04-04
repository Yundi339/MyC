class Solution {
	vector<string> board;
	bool IsQueen(int x, int y) {
		// 斜上方
		for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
			if (board[i][j] == 'Q')
				return false;
		}
		for (int i = x - 1, j = y + 1; i >= 0 && j < board.size(); i--, j++) {
			if (board[i][j] == 'Q')
				return false;
		}
		return true;
	}
public:
	vector<vector<string>> solveNQueens(const int n) {
		if (n == 1) return { {"Q"} };
		vector<vector<string>> ans;
		board = vector<string>(n, string(n, '.'));
		bitset<9> queen_col;
		auto dfs = [&](auto&& me, int q)->void {
			if (q == n) {
				ans.push_back(board);
				return;
			}
			for (int i = 0; i < n; ++i) {
				if (!queen_col[i] && IsQueen(q,i)) {
					board[q][i] = 'Q';
					queen_col[i] = true;
					me(me, q + 1);
					board[q][i] = '.';
					queen_col[i] = false;
				}
			}
		};
		std::function<void(decltype(dfs), int)> DFS = dfs;
		DFS(dfs, 0);
		return ans;
	}
};