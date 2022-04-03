class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		if (nums.size() < 4) return {}; // 数组长度不足4
		sort(nums.begin(), nums.end());// 排序
		int len = nums.size();
		if ((long)nums[0] + nums[1] + nums[2] + nums[3] > target || (len>5 && (long)nums[len - 1] + nums[len - 2] + nums[len - 3] + nums[len - 4] < target))
			return {};
		vector<vector<int>> ans;
		for (size_t i = 0; i < len - 3; ++i)
		{
			if (i && nums[i] == nums[i - 1]) continue;
			if ((long)nums[i] + nums[i + 1] + nums[i + 2]+ nums[i + 3] > target || (long)nums[i] + nums[len - 3] + nums[len - 2] + nums[len - 1] < target)
				continue;
			for (size_t j = i+1; j < len-2; ++j)
			{
				if (j!=i+1 && nums[j] == nums[j - 1]) continue;
				long ab = nums[i] + nums[j];
				if (ab + nums[j + 1] + nums[j + 2] > target || ab + nums[len - 2] + nums[len - 1] < target)
					continue;
				int left = j + 1;
				int right = len - 1;
				while (left <right)
				{
					long abcd = ab + nums[left] + nums[right];
					if (abcd < target) {
						++left;
					}
					else if (abcd > target) {
						--right;
					}
					else {
						ans.push_back({ nums[i],nums[j],nums[left],nums[right] });
						++left;
						--right;
						
						while (left < right && nums[left] == nums[left - 1]) { ++left; }
						while (left < right && nums[right] == nums[right + 1]) {--right; }
					}
				}
			}
		}
		return ans;
	}
};