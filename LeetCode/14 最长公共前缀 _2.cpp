bool cmp(string s1, string s2) { return s1.length() < s2.length(); }
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		// 找到最短字符串作为最长公共前缀
		sort(strs.begin(),strs.end(), cmp); // 按照长度排序
		vector<string>::iterator it = strs.begin();
		vector<string>::iterator temp = it+1;
		int max_len = it->length();
		while (max_len && temp !=strs.end())
		{
			int cur_len = 0;
			while (cur_len<max_len && (*it)[cur_len] == (*temp)[cur_len])
				++cur_len;
			max_len = cur_len;
			++temp;
		}
		return it->substr(0, max_len);
	}
};
