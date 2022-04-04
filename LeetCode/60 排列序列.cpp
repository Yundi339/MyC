class Solution {
public:
	string getPermutation(int n, int k) {
		// n-1的阶乘
		const int factorial[] = {1,1,2,6,24,120,720,5040,40320 };
		vector<char> nums = {'1', '2', '3','4','5','6','7','8','9' };
		string ans = "";
		// 序号映射
		int index;
		n--; 
		k--;
		while (n >= 0) {
			index = k / factorial[n];
			ans += nums[index];
			nums.erase(nums.begin() + index);
			k %= factorial[n];
			n--;
		}
		return ans;
	}
};