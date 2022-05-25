class Solution {
private:
	vector<vector<int>> ans;
	vector<int> nums;

public:
	void dfs(vector<int> temp, int level) {
		ans.push_back(temp);
		for (int i = level; i < nums.size(); i++) {
			temp.push_back(nums[i]);
			dfs(temp, i + 1);
			temp.pop_back();
		}

	}	
	vector<vector<int>> subsets(vector<int>& nums) {
		this->nums = nums;
		dfs({},0);
		return ans;
	}
};