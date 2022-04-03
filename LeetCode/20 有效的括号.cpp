#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

bool isValid(const string& s) {
	if (s.length() % 2 != 0) {
		return false;
	}
	stack<char> st;
	unordered_map<char, char> m;
	m.insert({ ')', '(' });
	m.insert({ ']', '[' });
	m.insert({ '}', '{' });
	for (char ch : s) {
		if (ch == '{' || ch == '(' || ch == '[')
			st.push(ch);
		else if (!st.empty() && m[ch] == st.top()){
			st.pop();
		}
		else {
			return false;
		}
	}
	if (st.empty())
		return true;
	else
		return false;
}

int main()
{
	string s;
	isValid("{}");
	return 0;
}