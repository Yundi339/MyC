class Solution {
private:
	string GetBlink(int n) {
        if (n<=0) return "";
		return string(n, ' ');
	}
	string GetString(vector<string>& words, queue<int>& myqueue, int sep_len, int sep_sum) {
		string s = words[myqueue.front()];
		myqueue.pop();
		int sep;
		while (!myqueue.empty()) {
			if (sep_sum != sep_len * myqueue.size()) {
				sep = sep_len + 1;
			}
			else {
				sep = sep_len;
			}
			s += GetBlink(sep) + words[myqueue.front()];
			sep_sum -= sep;
			myqueue.pop();
		}
		return s;
	}

public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> ans;
		
		int i = 0;
		while (i < words.size()) {
			// 一直加入字符串直到字符个数满
			queue<int> myqueue;
			int myqueue_len = 0;
			while (i < words.size() && myqueue_len + myqueue.size() + words[i].size() <= maxWidth) {
				myqueue_len += words[i].size();
				myqueue.push(i);
				i++;
			}
			if (myqueue.size() == 1) {
				ans.push_back(words[myqueue.front()] + GetBlink(maxWidth - myqueue_len));
			}
			else if (i == words.size()) {
				int t_len = maxWidth - myqueue_len - myqueue.size() +1 ;
				ans.push_back(GetString(words, myqueue, 1, myqueue.size()-1));
				ans.back() += GetBlink(t_len);
			}
			else {
				int sep_sum = maxWidth - myqueue_len;
				int sep_len = sep_sum / (myqueue.size() - 1);
				ans.push_back(GetString(words, myqueue, sep_len,sep_sum));
			}
		}
		return ans;
	}
};