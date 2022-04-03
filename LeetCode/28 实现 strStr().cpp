// 朴素模式匹配
// 1
class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.length() == 0) return 0;
		if (haystack.length() < needle.length()) return -1;
		int index = 0;
		int hi = 0;
		int ni = 0;
		while (hi + index < haystack.length()) {
			if (haystack[hi + index] == needle[ni]) {
				++index;
				++ni;
				if (index == needle.length())
					return hi;
			}
			else {
				++hi;
				index = 0;
				ni = 0;
			}
		}
		return -1;
	}
};
// 2
class Solution {
public:
	int strStr(string S, string T) {
		if (T.length() == 0) return 0;
		if (S.length() < T.length()) return -1;
		int i = 0;
		int j = 0;
		while (i < S.length() && j<T.length()) {
			if (S[i] == T[j]){
				++i; ++j;			
			}
			else {
				i = i - j + 1;
				j = 0;
			}
		}
		if (j == T.length())return i - j;
		else return -1;
	}
};