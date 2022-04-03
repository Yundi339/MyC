bool match(const char* s, const char* p) {
	if (*p == 0) return *s == 0;
	if (*s == 0) return *(p + 1) == '*' && match(s, p + 2);
	bool is_jump = (*s == *p || *p == '.');
	if (*(p + 1) == '*') {
		return match(s, p + 2) || (is_jump && match(s + 1, p));
	} else {
		return is_jump && match(s + 1, p + 1);
	}
}

class Solution {
public:
	bool isMatch(string s, string p) {
		string temp = "";
		char* last = nullptr;
		for (char& c : p) {
			if (c != '*' || (last && c != *last)) {
				temp += c;
				last = &c;
			}
		}
		return match(s.c_str(), temp.c_str());
	}
};
