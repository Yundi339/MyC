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
			int num;
			if (it1 != nums1.end() && it2 != nums2.end())
			{
				if (*it1 < *it2) {
					num = *it1;
					++it1;
				}
				else {
					num = *it2;
					++it2;
				}
			}
			else if (it1 != nums1.end()) {
				num = *it1;
				++it1;
			}
			else {
				num = *it2;
				++it2;
			}
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