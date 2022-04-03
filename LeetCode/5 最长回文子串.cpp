class Solution {
public:
	string longestPalindrome(string s) {
		if (s.empty()) {
			return s;
		}
		// 将字符串转变为奇数
		string temp = "$#";
		for (char& c : s)
		{
			temp += c;
			temp += '#';
		}
		temp += '@';

		int* len_arr = new int[temp.length()];
		int max_length = 1;
		int max_mid = 1;
		for (int i = 2; i < temp.length() - 2; i++)
		{
			len_arr[i]=1;
			// 更新当前位置回文半径
			while (temp[i + len_arr[i]] == temp[i - len_arr[i]]) {
				len_arr[i]++;
			}
			// 更新最大回文中心和最大回文半径
			if (len_arr[i] > max_length) {
				max_length = len_arr[i];
				max_mid = i;
			}
		}
		delete[]len_arr;
		string ans = s.substr((max_mid - max_length) >> 1, max_length - 1);
		return ans;
	}
};