void GetNext(string& T, int* next) {
	next[0] = -1;
	int i = 0;
	int k = -1;
	while (i < T.length()-1) {
		if (k == -1 || T[i] == T[k]) {
			next[++i] = ++k;
		}
		else {
			k = next[k];
		}
	}
}
class Solution {
public:
	int strStr(string S, string T) {
		if (T.length() == 0) return 0;
		if (S.length() < T.length()) return -1;
		int* next = new int[T.length()];
		GetNext(T, next);

		int i = 0;
		int j = 0;
		while (i+1 <= S.length() && j+1 <= T.length()) {
			if (j == -1 || S[i] == T[j]) {
				++i; ++j;
			}
			else {
				j = next[j];
			}
		}
		delete[] next;
		next = nullptr;
		if (j == T.length()) return i - j;
		else return -1;
	}
};