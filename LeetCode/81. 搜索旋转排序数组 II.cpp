class Solution {
public:
    bool search(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		int mid; // 防止溢出
		while (left <= right) {
			mid = left + ((right - left) >> 1);
			if (target == nums[mid]) {
				return true;
			}
			if (nums[mid] < nums[left]) {
				if (nums[mid] < target && target <= nums[right])
					left = mid + 1;
				else
					right = mid - 1;
			}
			else if (nums[mid] > nums[left]) {
				if (nums[left] <= target && target < nums[mid])
					right = mid - 1;
				else
					left = mid + 1;
			}
            else{
                left++;
            }
		}
		return false;
	}
};
