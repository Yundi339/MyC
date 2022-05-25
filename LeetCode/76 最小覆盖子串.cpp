class Solution {
public:
	string minWindow(string s, string t) {
		if (t.size() > s.size()) 
			return "";
		int t_map[255] = { 0, };
		int s_map[255] = { 0, };
		for (char& c : t) {
			t_map[c]++;
		}
		vector<int> char_vec;
		for (int i = 0; i < 255; i++) {
			if (t_map[i] != 0) {
				char_vec.push_back(i);
			}
		}
		auto check = [&]() -> bool {
			for (int& i : char_vec) {
				if (t_map[i] > s_map[i]) {
					return false;
				}
			}
			return true;
		};
		int ans_left = -1, ans_len = INT_MAX;
		int left = 0, right = -1;

		while (right+1 <= s.size()) {
			if (t_map[s[++right]] > 0) {
				s_map[s[right]]++;
			}
			while (check() && left <= right) {
				if (right - left + 1 < ans_len) {
					ans_len = right - left + 1;
					ans_left = left;
				}
				if (t_map[s[left]] > 0) {
					s_map[s[left]]--;
				}
				left++;
			}
		}
		return ans_len == INT_MAX ? "" : s.substr(ans_left, ans_len);
	}
};