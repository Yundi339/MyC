class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		const int word_len = words[0].length();
		const int word_sum = words.size();
		// 长度不足
		if (s.length() < words.size() * words[0].length()) return {};
		
		// 统计word个数
		vector<vector<int>> index_set(word_len, vector<int>{});
		vector<bool> bool_range(word_len, false);
		int count = 0;
		unordered_map<string,int> umap, t_umap;
		for (string& word : words) {
			umap[word]++;
			// 统计word在s中的所有出现位置,保证下标是连续的
			if (umap[word] == 1) {
				int cur = 0;
				while ((cur = s.find(word, cur)) != string::npos) {
					int i = cur % word_len;
					index_set[i].push_back(cur);
					bool_range[i] = 1;
					cur++;
					count++;
				}
			}
		}

		// 匹配字符串总数不足
		if (count < word_sum)return {};
		deque<pair<int, string>> slide_window;

		// 使用滑动窗口遍历index_set
		vector<int> ans;
		for (int i = 0; i < word_len; ++i) {
			if (!bool_range[i]) continue;
			vector<int>& cur_vector = index_set[i];
			sort(cur_vector.begin(), cur_vector.end()); // 下标排序
			t_umap = umap;
			slide_window.clear();
			for(int j = 0; j < cur_vector.size(); ++j){
				int& cur_index = cur_vector[j];
				string cur_str = s.substr(cur_index, word_len); // 获得当前字符串
				// 滑动窗口非空 && 下标不连续 -> 清空
				if (!slide_window.empty() && cur_vector[j-1] + word_len != cur_index) {
					t_umap = umap;
					slide_window.clear();
				}
				// 当前字符串发生冲突，滑动窗口右移，j回退
				if (t_umap[cur_str] <= 0) {
					pair<int, string> temp = slide_window.front();
					slide_window.pop_front();
					t_umap[temp.second]++;
					j--; // 回退
					continue;
				}
				// 没有冲突，加入元素
				else {
					slide_window.push_back(make_pair(cur_index, cur_str)); // 元素加入滑动窗口末尾
					t_umap[cur_str]--; // 计数减一
				}
				// 滑动窗口满了,滑动窗口右移 -> 顶部元素下标加入结果中
				if (slide_window.size() == word_sum) {
					pair<int, string> temp = slide_window.front();
					slide_window.pop_front();
					ans.push_back(temp.first);
					t_umap[temp.second]++;
				}
			}
		}
		return ans;
	}
};