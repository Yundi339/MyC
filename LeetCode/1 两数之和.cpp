#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int res;
		int nums_size = nums.size();
		for (int i = 0; i < nums_size; ++i) {
			res = target - nums[i];
			for (int j = i + 1; j < nums_size; ++j) {
				if (nums[j] == res) {
					return { i,j };
				}
			}
		}
		return {};
	}
};

int main()
{

	return 0;
}
