class Solution {
public:
	bool canJump(vector<int>& nums) {
		nums.shrink_to_fit();
		int target = nums.size() - 1;
		if (target == 0) return true;
		int cur = nums[0];
		for (int i = 1; i <= cur; ++i) {
			cur = max(cur, nums[i] + i);
			if (cur >= target)
				return true;
		}
		return false;
	}
};