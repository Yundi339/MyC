/*
O(n)
*/
class Solution {
public:
	int search(vector<int>& nums, int target) {
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == target)
				return i;
		}
		return -1;
	}
};
/*
O(nlogn)
*/
class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() < 10) {
			for (int i = 0; i < nums.size(); ++i) {
				if (nums[i] == target)
					return i;
			}
			return -1;
		}
		int ans = -1;
		int left = 0;
		int right = nums.size() - 1;
		int mid; // 防止溢出
		while (left <= right) {
			mid = left + ((right - left) >> 1);
			if (target == nums[mid]) {
				ans = mid;
				break;
			}
			if (nums[mid] < nums[right]) {
				if (nums[mid] < target && target <= nums[right])
					left = mid + 1;
				else
					right = mid - 1;
			}
			else {
				if (nums[left] <= target && target < nums[mid])
					right = mid - 1;
				else
					left = mid + 1;
			}
		}
		return ans;
	}
};