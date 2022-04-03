class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1 || numRows >= s.length()) return s;
		vector<string> vt(numRows,"");
		bool flag = true;
		int index = 0;
		
		for(char& c : s) {
			vt[index] += c;
			index = flag ? index + 1 : index - 1;
			if (index == 0 || index == numRows - 1) {
				flag = !flag;
			}
		}
		string ans = "";
		for (string& t_vt : vt) {
			ans += t_vt;
		}
		return ans;
	}
};