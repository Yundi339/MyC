class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		vector<int> temp(nums.size());
		bitset<8> b;
		auto dfs = [&](auto&& me)->void {
			int index = b.count();
			for (size_t i = 0; i < nums.size(); i++) {
				if (!b[i]) {
					if (i && !b[i - 1] && nums[i] == nums[i - 1]) {
						continue;
					}
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
		ans.shrink_to_fit();
		return ans;
	}
};
