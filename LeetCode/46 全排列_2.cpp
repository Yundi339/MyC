class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		int size = 1;
		for (size_t i = 2; i <= nums.size(); i++){
			size *= i;
		}
		vector<vector<int>> ans;
		ans.reserve(size);

		queue<vector<int>> q1;
		queue<bitset<6>> q2;

		bitset<6> b;
		vector<int> temp(nums.size());
		for (size_t i = 0; i < nums.size(); i++)
		{
			temp[0] = nums[i];
			b[i] = true;
			q1.push(temp);
			q2.push(b);
			b[i] = false;
		}
		
		while (!q1.empty()) {
			temp = q1.front();
			b = q2.front();
			q1.pop();
			q2.pop();
			int index = b.count();
			if (index == nums.size()) {
				ans.push_back(temp);
			}
			for (size_t i = 0; i < nums.size(); i++) {
				if (!b[i]) {					
					temp[index] = nums[i];
					q1.push(temp);
					b[i] = true;
					q2.push(b);
					b[i] = false;
				}
			}
		}
		return ans;
	}
};