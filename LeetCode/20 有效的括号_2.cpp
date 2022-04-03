class Solution {
public:
	bool isValid(string s) {
		if (s.length() % 2 != 0) {
			return false;
		}
		unordered_map<char,char> umap{
			{')','('},{']','['},{'}','{'}
		};
		stack<char> mystack;
		for (char& c : s) {
			if (umap.find(c) == umap.end()) {
				mystack.push(c);
			}
			else {
				if (!mystack.empty() && umap[c] == mystack.top()) {
					mystack.pop();
				}
				else {
					return false;
				}
			}
		}
		return mystack.empty();
	}
};