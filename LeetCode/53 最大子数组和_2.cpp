class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int ans = nums[0];
		int sum = nums[0];
		for (size_t i = 1; i < nums.size(); i++){
			sum = max(nums[i], sum + nums[i]);
			ans = max(sum, ans);
		}
		return ans;
	}
};