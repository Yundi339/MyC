class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		const int word_len = words[0].length();
		const int word_sum = words.size();
		// 长度不足
		if (s.length() < word_sum * word_len) return {};

		// 统计word个数
		vector<bool> bool_range(word_len, false);
		// 下标-WORDID
		int* s_ID = new int[s.length()];
		vector<vector<int>> index_set(word_len);
		vector<int> ID_Count_map(word_sum, 0);

		sort(words.begin(), words.end());
		int ID = -1;
		for (int i = 0; i < words.size(); ++i) {
			if (i && words[i] == words[i - 1]) {
				++ID_Count_map[ID];
			}
			else {
				++ID;
				++ID_Count_map[ID];
				int cur_index = 0;
				while ((cur_index = s.find(words[i], cur_index)) != string::npos) {
					int t = cur_index % word_len;
					index_set[t].push_back(cur_index); // 加入对应下标的数组中
					s_ID[cur_index] = ID;
					bool_range[t] = 1;
					++cur_index;
				}
			}
		}
		vector<int> t_umap;

		vector<int> ans;
		for (int i = 0; i < word_len; ++i) {
			if (!bool_range[i] || index_set[i].size() < word_sum) continue;
			vector<int>& cur_vector = index_set[i];
			sort(cur_vector.begin(), cur_vector.end()); // 下标排序
			t_umap = ID_Count_map;
			queue<int> slide_window; // 滑动窗口 index
			for (int j = 0; j < cur_vector.size(); ++j) {
				int& cur_index = cur_vector[j];
				// 滑动窗口非空 && 下标不连续 -> 清空
				if (!slide_window.empty() && cur_vector[j - 1] + word_len != cur_index) {
					t_umap = ID_Count_map;
					slide_window = queue<int>();
				}
				// 当前字符串发生冲突，滑动窗口右移
				while (t_umap[s_ID[cur_index]] <= 0) {
					int temp = slide_window.front();
					slide_window.pop();
					++t_umap[s_ID[temp]];
				}
				// 没有冲突，加入元素
				slide_window.push(cur_index); // 元素加入滑动窗口末尾
				--t_umap[s_ID[cur_index]]; // 计数减一

				// 滑动窗口满了,滑动窗口右移 -> 顶部元素下标加入结果中
				if (slide_window.size() == word_sum) {
					int temp = slide_window.front();
					slide_window.pop();
					ans.push_back(temp);
					++t_umap[s_ID[temp]];
				}
			}
		}
		delete[] s_ID;
		return ans;
	}
};