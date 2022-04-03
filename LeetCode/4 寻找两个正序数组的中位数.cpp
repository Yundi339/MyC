class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		double ans;
		vector<int> num3;
		num3.resize(nums1.size() + nums2.size());
		merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), num3.begin());
		sort(num3.begin(), num3.end());
		bool isOdd = (num3.size() % 2 == 1);
		int index = num3.size() / 2;
		if (isOdd) {
			ans = num3[index];
		}
		else {
			ans = num3[index] + num3[index - 1];
			ans /= 2;
		}
		return ans;
	}
};