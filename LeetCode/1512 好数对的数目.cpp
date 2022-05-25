class Solution {
public:
    int numIdenticalPairs(vector<int>& nums);
};
int Solution::numIdenticalPairs(vector<int>& nums){
	unordered_map<int, int> index_count_map;
	for (int& i : nums) {
		index_count_map[i]++;
	}
	int ans = 0;
	int value;
	for (auto& it : index_count_map) {
		value = it.second;
		if (value > 1) {
			int count = (value - 1) * value / 2;
			ans += count;
		}
	}
	return ans;
}