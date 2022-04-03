// IsOver(int_max, max_min_len, cur_num, cur_index, len)
// IsOver(int_min, max_min_len, cur_num, cur_index, len)
bool IsOver(int* arr, int arr_len, int num, int num_index, int num_len) {
	int t = -num;
	for (int i = num_len - num_index - 1; i < arr_len; ++i) {
		arr[i] += t;
		if (arr[i] < 0) {
			arr[i] += 10;
			t = -1;
		}
		else {
			return false;
		}
	}
	return (t == -1);
}

class Solution {
public:
	int reverse(int x) {
		int int_max[] = { 7,4,6,3,8,4,7,4,1,2 };
		int int_min[] = { 8,4,6,3,8,4,7,4,1,2 };
		int max_min_len = 10;
		bool flag = (x < 0); // 标记正负号 true为负号 false为正号

		int len = 0; // 获得长度
		int temp = x;
		// 更新长度
		while (temp != 0)
		{
			temp /= 10;
			len++;
		}
		int cur_num; // 当前整数
		int ans = 0;

		for (int cur_index = 0; cur_index < len; ++cur_index)
		{
			cur_num = x % 10;
			// 检查溢出
			if (flag) {
				if (IsOver(int_min, max_min_len, -cur_num, cur_index, len))
					return 0;
			}
			else {
				if(IsOver(int_max, max_min_len, cur_num, cur_index, len))
					return 0;
			}
			ans = ans * 10 + cur_num; //产生整数溢出
			x /= 10;
		}
		return ans;
	}
};