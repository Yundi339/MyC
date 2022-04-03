class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.size() < 1) return { -1,-1 };
		int left = 0;
		int right = nums.size() - 1;
		int mid;
		while (left <= right) {
			mid = ((right - left) >> 1) + left;
			if (nums[mid] == target) {
				break;
			}
			else if (nums[mid] < target) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		if (left <= right) {
			left = right = mid;
			while (left > 0 && nums[left-1] == target) {
				--left;
			}
			while (right < nums.size()-1 && nums[right+1] == target) {
				++right;
			}
			return {left,right};
		}
		else {
			return { -1,-1 };
		}
	}
};
// 特例
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.size() < 1 || nums[0] > target || nums[nums.size() - 1] < target) return { -1,-1 };
		int left = 0;
		int right = nums.size() - 1;
		int mid;
		if (nums.size() < 10) {
			for (left = 0; left < nums.size(); ++left) {
				if (nums[left] == target) {
					mid = left;
					break;
				}
			}
		}
		else {
			while (left <= right) {
				mid = ((right - left) >> 1) + left;
				if (nums[mid] == target) {
					break;
				}
				else if (nums[mid] < target) {
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}
		}

		if (left <= right) {
			left = right = mid;
			while (left > 0 && nums[left - 1] == target) {
				--left;
			}
			while (right < nums.size() - 1 && nums[right + 1] == target) {
				++right;
			}
			return { left,right };
		}
		else {
			return { -1,-1 };
		}
	}
};