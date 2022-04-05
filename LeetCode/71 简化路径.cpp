class Solution {
public:
	string simplifyPath(string path) {
		vector<string> mystack;
		string temp;
		int index = 0;
		while (index != path.size()) {
			temp = "";
			while (path[index] == '/')
				index++;
			while (index != path.size() && path[index] != '/') {
				temp += path[index];
				index++;
			}
			if (temp == ".")
				continue;
			else if (temp == "..") {
				if (!mystack.empty())
					mystack.pop_back();
			}
			else if (temp.length() > 0) {
				mystack.push_back(std::move(temp));
			}
		}
			   
		string ans;
		if (mystack.empty()) {
			ans = "/";
		}
		else {
			for (string& t : mystack) {
				ans += ('/' + std::move(t));
			}
		}
		return ans;
	}
};