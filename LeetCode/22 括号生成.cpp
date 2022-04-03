#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

vector<string> generateParenthesis(int n) {
	vector<string> ans;
	queue<tuple<int,int,string>> qt;
	tuple<int, int, string> tt;
	qt.push(make_tuple( 0,0,"" ));
	int l = 0, r = 0;
	string s;
	while (!qt.empty()) {
		tie(l, r, s) = qt.front();
		qt.pop();
		if (l > n || r > l) continue;
		if (l == n && r == n) {
			ans.push_back(s);
			continue;
		}
		if (l < n) {
			qt.push(make_tuple(l+1, r, s + "("));
		}
		if (r < n) {
			qt.push(make_tuple(l,r+1,s+")"));
		}
	} 
	return ans;
}

int main() {
	for (string s : generateParenthesis(3))
		cout << s << " " << endl;
	return 0;
}