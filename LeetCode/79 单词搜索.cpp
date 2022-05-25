class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		int m = board.size();
		int n = board[0].size();
		vector<vector<bool>> map(m,vector<bool>(n));
		int count = 0;

		auto dfs = [&](auto&& me, int i, int j)-> bool{
			if (count == word.size()) {
				return true;
			}
			// up
			if (i - 1 >= 0 && !map[i - 1][j] && board[i-1][j] == word[count]) {
				map[i - 1][j] = 1;
				count++;
				if (me(me, i - 1, j)) return true;
				count--;
				map[i - 1][j] = 0;
			}
			// down
			if (i + 1 < m && !map[i + 1][j] && board[i + 1][j] == word[count]) {
				map[i + 1][j] = 1;
				count++;
				if (me(me, i + 1, j)) return true;
				count--;
				map[i + 1][j] = 0;
			}
			// left
			if (j - 1 >= 0 && !map[i][j - 1] && board[i][j - 1] == word[count]) {
				map[i][j - 1] = 1;
				count++;
				if (me(me, i, j - 1)) return true;
				count--;
				map[i][j - 1] = 0;
			}
			// right
			if (j + 1 < n && !map[i][j + 1] && board[i][j + 1] == word[count]) {
				map[i][j + 1] = 1;
				count++;
				if (me(me, i, j + 1)) return true;
				count--;
				map[i][j + 1] = 0;
			}
			return false;
		};
		std::function<bool(decltype(dfs), int, int)> DFS = dfs;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == word[0]) {
					count = 1;
					map[i][j] = 1;
					if (DFS(dfs,i,j)) {
						return true;
					}
					map[i][j] = 0;
				}
			}
		}
		return false;
	}
};