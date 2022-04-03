bool cmp(const pair<int, int>& a,const pair<int, int>& b) {
	return a.first < b.first;
}

void clear(queue<pair<int, int>>& Q) {
	queue<pair<int, int>> emp;
	swap(Q, emp);
}
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		const int word_len = words[0].length();
		const int word_sum = words.size();
		// 长度不足
		if (s.length() < words.size() * words[0].length()) return {};

		// 统计word个数
		vector<bool> bool_range(word_len, false);
		// 下标-WORDID
		vector<vector<pair<int, int>>> index_ID_set(word_len);
		//unordered_map<string, int> Word_ID_map;
		unordered_map<int, int> ID_Count_map, t_umap;

		sort(words.begin(),words.end());
		int ID = -1;
		for (int i = 0; i < words.size(); ++i) {
			if (i && words[i] == words[i - 1]) {
				++ID_Count_map[ID];
			}
			else {
				++ID;
				//Word_ID_map[words[i]] = ID; // 加入字典
				++ID_Count_map[ID];
				int cur = 0;
				while ((cur = s.find(words[i], cur)) != string::npos) {
					int t = cur % word_len;
					index_ID_set[t].push_back(make_pair(cur, ID)); // 加入对应下标的数组中
					bool_range[t] = 1;
					++cur;
				}
			}
		}

		// 滑动窗口 index_ID
		queue<pair<int, int>> slide_window;
		// index_ID
		pair<int, int> temp;
		vector<int> ans;
		for (int i = 0; i < word_len; ++i) {
			if (!bool_range[i]|| index_ID_set[i].size()<word_sum) continue;
			vector<pair<int, int>> cur_vector = index_ID_set[i];
			sort(cur_vector.begin(), cur_vector.end(), cmp); // 下标排序
			t_umap = ID_Count_map;
			clear(slide_window);
			for (int j = 0; j < cur_vector.size(); ++j) {
				pair<int, int>& cur_index_ID = cur_vector[j];
				// 滑动窗口非空 && 下标不连续 -> 清空
				if (!slide_window.empty() && cur_vector[j - 1].first + word_len != cur_index_ID.first) {
					t_umap = ID_Count_map;
					clear(slide_window);
				}
				// 当前字符串发生冲突，滑动窗口右移
				while (t_umap[cur_index_ID.second] <= 0){
					temp = slide_window.front();
					slide_window.pop();
					++t_umap[temp.second];
				}
				// 没有冲突，加入元素
				slide_window.push(cur_index_ID); // 元素加入滑动窗口末尾
				--t_umap[cur_index_ID.second]; // 计数减一

				// 滑动窗口满了,滑动窗口右移 -> 顶部元素下标加入结果中
				if (slide_window.size() == word_sum) {
					temp = slide_window.front();
					slide_window.pop();
					ans.push_back(temp.first);
					++t_umap[temp.second];
				}
			}
		}
		return ans;
	}
};
};