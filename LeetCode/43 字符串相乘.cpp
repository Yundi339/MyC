class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0") return "0";
		if (num1.size() > num2.size()) {
			swap(num1, num2);
		}
		int len = num1.size() + num2.size();
		int* temp = new int[len];
		memset(temp, 0, sizeof(int) * len);

		for (int i = num1.size()-1; i >= 0; i--) {
			int c1 = num1[i] - '0';
			if (c1 == 0) continue;
			for (int j = num2.size()-1; j >= 0; j--) {
				int c2 = num2[j] - '0';
				int t = temp[i + j + 1] + c1 * c2;
				temp[i + j + 1] = t % 10;
				temp[i + j] += t / 10;
			}
		}
		string ans;
		int index = 0;
		while (temp[index] == 0) index++;
		for (size_t i = index; i < len; i++) {
			ans += ('0' + temp[i]);

		}
		delete[] temp;
		return ans;
	}
};