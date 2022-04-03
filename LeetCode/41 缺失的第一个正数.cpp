class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		nums.shrink_to_fit();
		for (size_t i = 0; i < nums.size(); ++i)
			if (nums[i] != i + 1) {
				while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i])
					swap(nums[i], nums[nums[i] - 1]);
			}
		for (size_t i = 0; i < nums.size(); ++i)
			if (nums[i] != i + 1)
				return i + 1;
		return nums.size() + 1;
	}
};