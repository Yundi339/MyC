class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		// 先倒序寻找第一个逆序的数字，后面升序，再替换第一个比大的数字
		int right = nums.size() - 1;
		int left = right-1;
		while (left >= 0) {
			if (nums[left] < nums[left + 1]) {
				break;
			}
			--left;
		}
		if (left == -1) {
			sort(nums.begin(), nums.end());
			return;
		}
		sort(nums.begin() + left + 1, nums.end());
		right = left + 1;
		while (right < nums.size()) {
			if (nums[right] > nums[left]) {
				swap(nums[right] , nums[left]);
				break;
			}
			++right;
		}
	}
};