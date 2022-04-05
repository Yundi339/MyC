class Solution {
public:
	string addBinary(string a, string b) {
		if (a.length() < b.length()) swap(a, b);
		int t = 0;
		string ans = "";
		int i = a.size() - 1, j = b.size() - 1;
		for (; j >= 0; --i, --j)
		{
			t += a[i] - '0' + b[j] - '0';
			ans += ((t % 2) ? '1' : '0');
			t /= 2;
		}
		for (; i >= 0; --i)
		{
			t += a[i] - '0';
			ans += ((t % 2) ? '1' : '0');
			t /= 2;
		}
		if (t > 0) {
			ans += '1';
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};