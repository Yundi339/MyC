// https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/
class Solution {
public:
    string removeDuplicates(string s);
};
string Solution::removeDuplicates(string s) {
	string ans = "";
	for (char& cur : s) {
		// 判断非空栈的栈顶字符是否等于当前字符
		if (!ans.empty() && ans.back() == cur) {
			ans.pop_back();
		}
		else {
			ans.push_back(cur);
		}
	}
	return ans;
}
