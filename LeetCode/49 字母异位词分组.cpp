class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> umap;
		vector<vector<string>> ans;
		string temp;
		for (string& s : strs) {
			temp = s;
			sort(temp.begin(), temp.end());
			umap[temp].push_back(std::move(s));
		}
		ans.reserve(umap.size());
		for (auto& kv : umap) {
			ans.push_back(std::move(kv.second));
		}
		return ans;
	}
};