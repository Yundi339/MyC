void replace(string& s, string str1, string str2) {
	int pos = 0;
	int cur = 0;
	while ((pos = s.find(str1,cur)) != string::npos){
		s.replace(pos, str1.size(), str2);
		cur = pos + str2.size();
	}
}

class Solution {
public:
	int romanToInt(string s) {
		static unordered_map<char, int> dict
		{
			{'M',1000},
			{'6',900},
			{'D',500},
			{'5',400},
			{'C',100},
			{'4',90},
			{'L',50},
			{'3',40},
			{'X',10},
			{'2',9},
			{'V',5},
			{'1',4},
			{'I',1},
		};
		replace(s, "IV", "1");
		replace(s, "IX","2");
		replace(s, "XL","3");
		replace(s, "XC","4");
		replace(s, "CD","5");
		replace(s, "CM","6");
		int ans =0;
		for (char& c : s)
			ans += dict[c];
		return ans;
	}
};