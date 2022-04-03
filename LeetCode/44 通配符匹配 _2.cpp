class Solution {
public:
	bool isMatch(string s, string p) {
		string _p = "";
		char* last = nullptr;
		for (char& c : p) {
			if (c != '*' || !last || c != *last) {
				_p += c;
				last = &c;
			}
		}
		p = _p;
		if (p == "*")
			return true;
		int si = 0;
		int pi = 0;
		int s_back=0;
		int p_back = -1;
		while(si<s.size()) {
			if (pi < p.length()) {
				if (s[si] == p[pi] || p[pi] == '?') {
					++pi;
					++si;
					continue;
				}
				// 不匹配*
				if (p[pi] == '*')
				{
					s_back = si;
					++pi;
					p_back = pi;
					continue;
				}
			}
			// 回退，匹配*
			if (p_back != -1) {
				++s_back;
				si = s_back;
				pi = p_back;
				continue;
			}
			return false;
		}
		if (pi == p.size() || (pi == p.size() - 1 && p[pi] == '*')) return true;
		return false;
	}
};