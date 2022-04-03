class Solution {
public:
	int trap(vector<int>& height) {
		height.shrink_to_fit();
		if (height.size() < 3) return 0;
		int len = height.size();
		vector<int> left(len), right(len);
		left[0] = height[0];
		right[len - 1] = height[len - 1];
		for (size_t i = 1, j = len - 2; i < len - 1; i++, j--)
		{
			left[i] = max(left[i - 1], height[i]);
			right[j] = max(right[j+1], height[j]);

		}
		int ans = 0;
		for (size_t i = 1; i < len - 1; i++)
		{
			ans += min(left[i], right[i]) - height[i];
		}
		return ans;
	}
};