class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (target <= nums[0])return 0;
		if (target > nums[nums.size() - 1])return nums.size();
		if (nums.size() < 3) {
			for (int i = 0; i < nums.size(); ++i) {
				if (nums[i] >= target)
					return i;
			}
		}
		int left = 0;
		int right = nums.size() - 1;
		int mid;
		while (left <= right) {
			mid = ((right - left) >> 1) + left;
			if (nums[mid ] == target) {
				return mid;
			}
			else if (nums[mid] > target) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		return right + 1;;
	}
};