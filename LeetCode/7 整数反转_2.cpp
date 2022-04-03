#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
bool ArrSub(vector<int>& v1, vector<int>& v2) {
	if (v1[0] < v2[0])return true;
	int t = 0;
	for (int i = v1.size() - 1; i >= 0; --i) {
		if (v1[i] - t - v2[i] < 0) {
			t = 1;
		}
		else {
			t = 0;
		}
	}
	return (t == 1);
}

class Solution {
public:
	int reverse(int num) {
		constexpr int max_min_len = 10;
		vector<int> inf_arr{ 2,1,4,7,4,8,3,6,4,7 };
		vector<int> rev_arr;
		bool flag = (num < 0); // 标记正负号 true为负号 false为正号
		if (flag) inf_arr[max_min_len - 1]++;
		int sign = flag ? -1 : 1; 
		// 整数转翻转数组
		while (num != 0) {
			rev_arr.push_back((num % 10) * sign);
			num /= 10;
		}
		// 补全长度
		int diff = max_min_len - rev_arr.size();
		rev_arr.insert(rev_arr.begin(), diff, 0);
		// 判断整数相减结果
		if (ArrSub(inf_arr, rev_arr)) {
			return 0;
		}
		int ans = 0; // 防止-2^32溢出
		for (int i = diff; i < max_min_len; ++i) {
			ans = ans * 10 + sign * rev_arr[i];
		}
		return ans;
	}
};