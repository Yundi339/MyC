class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> ans;
		queue<tuple<int,int, string>> myqueue;
		string str;
		int left,right;
		myqueue.push(make_tuple(0,0, ""));
		for (size_t i = 0; i < 2*n-1; ++i) {
			int cur_queue_size = myqueue.size();
			for (size_t j = 0; j < cur_queue_size; ++j)
			{
				tie(left, right,str) = myqueue.front();
				myqueue.pop();
				if (left > right)myqueue.push(make_tuple(left, right + 1, str + ')'));
				if (left < n)myqueue.push(make_tuple(left + 1, right, str + '('));
			}
		}
		while (!myqueue.empty()) {
			tie(left, right, str) = myqueue.front();
			myqueue.pop();
			ans.push_back(str + ')');
		}
		return ans;
	}
};