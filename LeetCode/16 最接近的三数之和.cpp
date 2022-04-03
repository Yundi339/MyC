class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int len = nums.size();
		int ans = nums[0] + nums[1] + nums[2];
		if (len == 3) {
			return ans;
		}		
		sort(nums.begin(), nums.end());
		int opt_diff = abs(ans - target);
		for (int i = 0; i < len - 2; ++i) {
			if (i && nums[i - 1] == nums[i]) continue;
			int left = i + 1, right = len - 1;
			while (left < right) {
				int t = nums[i] + nums[left] + nums[right]; // 当前三数之和
				if (t == target)
					return target;
				// 计算误差
				int diff = abs(t - target);
				if (diff < opt_diff) {
					ans = t;
					opt_diff = diff;
				}
				// 双指针移动+防止重复元素
				if (t < target) {
					++left;
					while (left < right && nums[left] == nums[left - 1])
						++left;
				}
				else {
					--right; 
					while (left < right && nums[right] == nums[right + 1]) --right;
				}	
			}
		}
		return ans;
	}
};
