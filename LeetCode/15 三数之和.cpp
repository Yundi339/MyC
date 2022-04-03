class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		int len = nums.size();
		if (len < 3)return {};
		// 排序
		sort(nums.begin(), nums.end());
		if (nums[0] > 0 || nums[len - 1] < 0) return {};
		if (!nums[0] && !nums[len - 1])return { { 0,0,0 } };
		vector<vector<int>> ans;
		ans.reserve(len < 128 ? (len < 256 ? len : 256) : 128);
		int left, right, mid;
		for (int i = 0; i < len -2; ++i) {
			if (nums[i] > 0) break;
			if (i && nums[i - 1] == nums[i]) continue;
			int left = i + 1;
			int right = len - 1;
			while (left < right) {
				int target = nums[i] + nums[left] + nums[right];
				if (target < 0)
					++left;
				else if (target > 0)
					--right;
				else {
					ans.push_back({ nums[i],nums[left], nums[right] });
					++left;
					--right;
					while (left < right && nums[left] == nums[left - 1]) ++left;
					while (left < right && nums[right] == nums[right + 1]) --right;					
				}
			}
		}
		return ans;
	}
};