class Solution {
public:
	int jump(vector<int>& nums) {
		int target = nums.size() - 1;
		int i = 0, j, k, start = i + 1, max_index, max_value, cur, step = 0;
		while (i < target) {
			cur = nums[i] + i;
			if (cur >= target) {
				return step + 1;
			}
			max_index = cur;
			max_value = nums[cur] + cur;
			for (j = cur; j >= start; j--) {
				int n = nums[j] + j;
				if (n >= target) {
					return step + 2;
				}
				if (n > max_value) {
					max_index = j;
					max_value = n;
				}
			}
			++step;
			start = cur + 1;
			i = max_index;
		}
		return step;
	}
};