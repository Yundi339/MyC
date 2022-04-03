class Solution {
public:
	int jump(const vector<int>& nums) {
		int target = nums.size() - 1;
		if (target == 0) return 0;
		if (target == 1 || nums[0] >= target)return 1;
		int ans = 1;
		int end = nums[0];
		int cur = nums[0];
		for (int i = 1; i <= target; ++i) {
			end = max(end, nums[i]+i);
			if (i == cur) {
				cur = end;
				ans++;
				if (cur >= target)
					return ans;
			}
		}
		return ans;
	}
};