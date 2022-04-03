class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if (digits.length() == 0) return {};
		unordered_map<char, string> str_map{
			{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}
		};
		unordered_map<char, int> len_map{
			{'2',3},{'3',3},{'4',3},{'5',3},{'6',3},{'7',4},{'8',3},{'9',4}
		};
		queue<string> qans;
		qans.push("");
		int vlen = 1;
		for (char c : digits) vlen *= len_map[c]; // 计算结果长度
		vector<string> ans;
		ans.reserve(vlen);
		int i = 0;
		for (char& c : digits) {
			int qlen = qans.size();
			for (size_t i = 0; i < qlen; ++i)
			{
				string cur_str = qans.front();
				qans.pop();
				for (int j = 0; j < len_map[c]; ++j) {
					qans.push(cur_str + str_map[c][j]);
				}
			}
		}
		while (!qans.empty()) {
			ans.push_back(qans.front());
			qans.pop();
		}
		return ans;
	}
};
