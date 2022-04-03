class Solution {
private:
	string last_str = "1";
public:
	string countAndSay(int n) {
		if (n == 1) return last_str;
		string cur_str = "";
		char last_char = last_str[0];
		int count = 1;

		for (int i = 1; i < last_str.length(); ++i) {
			if (i && last_str[i] == last_char) {
				count++;
				continue;
			}
			else {
				cur_str += ('0' + count);
				cur_str += last_char;
				count = 1;
				last_char = last_str[i];
			}
		}
		cur_str += ('0' + count);
		cur_str += last_char;
		last_str = cur_str;
		return countAndSay(n-1);
	}
};
