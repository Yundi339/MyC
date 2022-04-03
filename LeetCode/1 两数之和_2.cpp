#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> umap;
		int nums_size = nums.size();
		for (int i = 0; i < nums_size; ++i) {
			if (umap.find(nums[i]) == umap.end()) {
				umap[target-nums[i]] = i;
			}
			else {
				return { i, umap[nums[i]] };
			}
		}
		return {};
	}
};

int main()
{

	return 0;
}
