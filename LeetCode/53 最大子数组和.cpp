class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int ans = nums[0];
		int sum = 0;
		for (int& n : nums){
			sum = max(n, sum + n);
			ans = max(sum, ans);
		}
		return ans;
	}
};