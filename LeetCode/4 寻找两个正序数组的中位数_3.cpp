#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int GetNum(vector<int>::iterator& it1, vector<int>::iterator& it2, int mode) {
	int num;
	switch (mode)
	{
	case 0:
		if (*it1 < *it2) {
			num = *it1;
			++it1;
		}
		else {
			num = *it2;
			++it2;
		}
		break;
	case 1:
		num = *it1;
		++it1;
		break;
	case 2:
		num = *it2;
		++it2;
		break;
	default:
		break;
	}
	return num;
}
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		double ans = 0;
		int new_size = nums1.size() + nums2.size();
		bool isOdd = (new_size % 2 == 0);
		int mid_index = new_size / 2;
		int mid_odd = mid_index - 1;
		int index = 0;
		vector<int>::iterator it1 = nums1.begin();
		vector<int>::iterator it2 = nums2.begin();
		while (index <= mid_index) {
			int mode = ((it1 == nums1.end()) << 1) | (it2 == nums2.end());
			int num = GetNum(it1, it2, mode);
			if (index >= mid_odd) {
				if (index == mid_odd) {
					if (isOdd) {
						ans = num;
					}
				}
				else{
					if (isOdd) {
						ans += num;
						ans /= 2;
					}
					else {
						ans = num;
					}
					break;
				}
			}
			index++;
		}
		return ans;
	}
};

int main()
{
	vector<int> nums1= { 1,2 };
	vector<int> nums2 = { 3,4 };
	Solution s;
	cout << s.findMedianSortedArrays(nums1, nums2);
	return 0;
}
