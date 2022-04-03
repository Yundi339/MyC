class Solution {
public:
	vector<vector<int>> permute(const vector<int>& nums) {
		vector<vector<int>> ans;
		vector<int> temp(nums.size());
		bitset<6> b;
		auto dfs = [&](auto&& me)->void {
			int index = b.count();
			for (size_t i = 0; i < nums.size(); i++) {
				if (!b[i]) {
					temp[index] = nums[i];
					if (index + 1 == nums.size())
						ans.push_back(temp);
					else {
						b[i] = true;
						me(me);
					}
					b[i] = false;
				}
			}
		};
		std::function<void(decltype(dfs))> DFS = dfs;
		DFS(dfs);
		return ans;
	}
};