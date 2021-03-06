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
		int left = 0;
		int right = nums.size() - 1;
		int mid; // 防止溢出
		while (left <= right) {
			mid = left + ((right - left) >> 1);
			if (target == nums[mid]) {
				return mid;
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
		return -1;
	}
};
