// 方法一
class Solution {
	void QuickSort(vector<int>& nums, int left,int right) {
		auto partition = [&](int left, int right)->int {
			int key = nums[right];
			int index = left;
			for (int i = left; i < right; i++) {
				if (nums[i] <= key) {
					swap(nums[index++], nums[i]);
				}
			}
			swap(nums[index], nums[right]);
			return index;
		};
		if (left < right) {
			int p = partition(left, right);
			QuickSort(nums, left, p - 1);
			QuickSort(nums, p + 1, right);
		}
	}
public:
	void sortColors(vector<int>& nums) {
		QuickSort(nums, 0, nums.size() - 1);
	}
};

// 方法二
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int left = 0;
		int right = nums.size()-1;
		for (int i = left; i <= right; i++) {
			if (nums[i] == 0) {
				swap(nums[i], nums[left++]);
			}
			else if (nums[i] == 2) {
                swap(nums[i], nums[right--]);
                if(nums[i] == 0|| nums[i] == 2) {
                    i--;
                }
			}
		}
	}
};