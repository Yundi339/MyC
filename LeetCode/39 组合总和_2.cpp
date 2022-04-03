class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> ans;
		vector<int> t_ans;
		auto dfs = [&](auto&& me, int sum, int index)->void {
			vector<int> temp = t_ans;
			int cur_num;
			for (int i = index; i < candidates.size(); ++i) {
				cur_num = sum + candidates[i];
				if (cur_num > target)
					break;
				while (cur_num <= target) {
					t_ans.push_back(candidates[i]);
					if (cur_num == target) {
						ans.push_back(t_ans);
					}
					else if (i < candidates.size() - 1 && cur_num + candidates[i + 1] <= target) {
						me(me, cur_num, i + 1);
					}
					cur_num += candidates[i];
				}
				t_ans = temp;
			}
		};
		std::function<void(decltype(dfs), int, int)> DFS = dfs;
		DFS(dfs, 0,0);
		ans.shrink_to_fit();
		return ans;
	}
};