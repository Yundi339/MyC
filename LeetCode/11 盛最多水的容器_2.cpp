class Solution {
public:
	int maxArea(vector<int>& height) {
		int max_area = 0;
		int area;
		vector<int>::iterator left = height.begin();
		vector<int>::iterator right = height.end() - 1;
		int len = height.size() - 1;
		while (len > 0)
		{
			if (*left < *right) {
				area = len * (*left);
				++left;
				--len;
			}
			else {
				area = len * (*right);
				--right;
				--len;
			}
			if (area > max_area)
				max_area = area;
		}
		return max_area;
	}
};