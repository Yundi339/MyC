class Solution {
public:
	int longestValidParentheses(string s) {
		stack<int> my_stack; // 存放下标
		vector<bool> s_valid(s.length()); // 当前位置是否合法
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == '(') my_stack.push(i);
			else if (!my_stack.empty()) {
				s_valid[my_stack.top()] = s_valid[i] = 1;
				my_stack.pop();
			}
		}
		int ans = 0;
		int cur_count = 0;
		for (int i = 0; i < s.length(); ++i) {
			if (s_valid[i])	++cur_count;
			else {
				ans = max(ans, cur_count);
				cur_count = 0;
			}
		}
		return max(ans, cur_count);
	}
};