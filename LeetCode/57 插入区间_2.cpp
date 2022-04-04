class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<vector<int>> ans;
		int i = 0;
		while (i < intervals.size() && intervals[i][0] < newInterval[0])
			++i;
		if (i == 0) {
			ans.push_back(newInterval);
		}
		else {
			ans.resize(i);
			ans.reserve(i+1);
			std::move(intervals.begin(), intervals.begin() + i, ans.begin());
			if (ans.back()[1] >= newInterval[0]) {
				ans.back()[1] = max(ans.back()[1], newInterval[1]);
			}
			else {
				ans.push_back(newInterval);
			}
		}
		if (i < intervals.size()) {
			while (i < intervals.size() && intervals[i][0] <= ans.back()[1]) {
				ans.back()[1] = max(ans.back()[1], intervals[i][1]);
				i++;
			}
			int origin = ans.size();
			int len = intervals.size() - i;
			ans.resize(origin + len);
			std::move(intervals.begin() + i, intervals.end(), ans.begin() + origin);
		}
		return ans;
	}
};