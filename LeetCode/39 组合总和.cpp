class Solution {
private:
	vector<vector<int>> ans;
	vector<int> g_candidates;
	vector<int> t_ans;
	int g_target;

	void DFS(int sum, int index)
	{
		if (index == g_candidates.size() - 1) {
			return;
		}
		vector<int> temp = t_ans;
		int cur_num;
		for (int i = index; i < g_candidates.size(); ++i) {
			cur_num = sum + g_candidates[i];
			if (cur_num > g_target) 
				break;
			while (cur_num <= g_target) {
				t_ans.push_back(g_candidates[i]);
				if (cur_num == g_target) {
					ans.push_back(t_ans);
				}
				else if (cur_num + g_candidates[i + 1] <= g_target) {
					DFS(cur_num, i + 1);
				}
				cur_num += g_candidates[i];
			}
			t_ans = temp;
		}
	}
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		g_candidates = candidates;
		g_target = target;
		DFS(0,0);
		return ans;
	}
};