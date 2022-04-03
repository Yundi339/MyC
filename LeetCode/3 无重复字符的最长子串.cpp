class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int* last_arr = new int[256];
		memset(last_arr, -1, sizeof(int) * 256);
		int ans = 0;
		int start = 0;
		for (int end = 0; end < s.length(); ++end) {
			start = max(last_arr[s[end]] + 1, start);
			ans = max(ans, end - start + 1);
			last_arr[s[end]] = end;
		}
		delete[]last_arr;
		last_arr = nullptr;
		return ans;
	}
};