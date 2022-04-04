class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		intervals.push_back(std::move(newInterval));
		sort(intervals.begin(), intervals.end());
		vector<vector<int>> ans;
		for (vector<int>& num : intervals) {
			if (!ans.size() || ans.back()[1] < num[0]) {
				ans.push_back(std::move(num));
			}
			else if (ans.back()[1] < num[1])
				ans.back()[1] = std::move(num[1]);
		}
		return ans;
	}
};