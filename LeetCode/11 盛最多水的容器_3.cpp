class Solution {
public:
	int maxArea(vector<int>& height) {
		int max_area = 0;
		vector<int>::iterator left = height.begin();
		vector<int>::iterator right = height.end() - 1;
		int len = height.size() - 1;
		while (len > 0)
		{
			int area;
			if (*left < *right) {
				int low = (*left);
				area = len * low;
				while (--len > 0 && *(++left) <= low);

			}
			else {
				int low = (*right);
				area = len * low;
				while (--len > 0 && *(--right) <= low);
			}
			if (area > max_area)
				max_area = area;
		}
		return max_area;
	}
};