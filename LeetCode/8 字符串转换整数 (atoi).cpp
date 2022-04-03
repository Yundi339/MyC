class Solution {
public:
	int myAtoi(string s) {
		string ss;
		bool flag = false;
		int sign = 1;

		// 删除前导空格
		int index = 0;
		while (s[index] == ' ')
			++index;
		// 判断符号
		if (s[index] == '-') 
		{ 
			flag = true; 
			sign = -1;
			++index;
		}
		else if(s[index] == '+'){

			++index;
		}
		// 截断字符串
		s = s.substr(index, s.length() - index);
		// 防止越界
		s += "#"; 
		// 遍历字符串保存数字
		for (int i = 0; i < s.length()-1; i++) {
			if ('0' <= s[i] && s[i] <= '9') {
				int len = 1;
				while ('0' <= s[i + len] && s[i + len] <= '9')
					len++;
				ss = s.substr(i, len); // 得到数字字符串
				break;
			}
			else { 
				break;
			}
		}
		// 字符串转数字
		long ans = 0;
		for (char& c : ss) {
			ans = ans * 10 + sign * (c - '0');
			if (flag){
				if (ans < INT_MIN) {
					return INT_MIN;
				}
			}else{
				if (ans > INT_MAX) {
					return INT_MAX;
				}
			}
		}
		return ans;
	}
};