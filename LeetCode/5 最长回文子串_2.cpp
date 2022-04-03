#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
	string longestPalindrome(string s) {
		if (s.empty()) {
			return s;
		}
		// 将字符串转变为奇数
		string temp = "$#";
		for (char& c : s)
		{
			temp += c;
			temp += '#';
		}
		temp += '@';

		int* len_arr = new int[temp.length()];
		len_arr[0] = len_arr[1] = 1;
		int max_length = 1;
		int max_mid = 1;

		int cur_mid = 1;
		int cur_right = 1;

		for (int i = 2; i < temp.length() - 2; i++)
		{
			// 初始化
			if (i < cur_right) {
				int j = cur_mid * 2 - i;  // (i+j)/2=cur_mid
				// 约束边界
				if (len_arr[j] < cur_right - i) {
					len_arr[i] = len_arr[j];
				}
				else {
					len_arr[i] = cur_right - i;
				}
			}
			else {
				len_arr[i] = 1;
			}
			// 更新当前位置回文半径
			while (temp[i + len_arr[i]] == temp[i - len_arr[i]]) {
				len_arr[i]++;
			}
			// 更新当前回文中心和当前半径
			if (len_arr[i] > cur_right - i) {
				cur_mid = i;
				cur_right = i + len_arr[i];
			}
			// 更新最大回文中心和最大回文半径
			if (len_arr[i] > max_length) {
				max_length = len_arr[i];
				max_mid = i;
			}
		}
		delete[]len_arr;
		string ans = s.substr((max_mid - max_length) >> 1, max_length - 1);
		return ans;
	}
};


int main()
{
	vector<int> nums1= { 1,2 };
	vector<int> nums2 = { 3,4 };
	Solution s;
	//string ss = "whdqcudjpisufnrtsyupwtnnbsvfptrcgvobbjglmpynebblpigaflpbezjvjgbmofejyjssdhbgghgrhzuplbeptpaecfdanhlylgusptlgobkqnulxvnwuzwauewcplnvcwowmbxxnhsdmgxtvbfgnuqdpxennqglgmspbagvmjcmzmbsuacxlqfxjggrwsnbblnnwisvmpwwhomyjylbtedzrptejjsaiqzprnadkjxeqfdpkddmbzokkegtypxaafodjdwirynzurzkjzrkufsokhcdkajwmqvhcbzcnysrbsfxhfvtodqabvbuosxtonbpmgoemcgkudandrioncjigbyizekiakmrfjvezuzddjxqyevyenuebfwugqelxwpirsoyixowcmtgosuggrkdciehktojageynqkazsqxraimeopcsjxcdtzhlbvtlvzytgblwkmbfwmggrkpioeofkrmfdgfwknrbaimhefpzckrzwdvddhdqujffwvtvfyjlimkljrsnnhudyejcrtrwvtsbkxaplchgbikscfcbhovlepdojmqybzhbiionyjxqsmquehkhzdiawfxunguhqhkxqdiiwsbuhosebxrpcstpklukjcsnnzpbylzaoyrmyjatuovmaqiwfdfwyhugbeehdzeozdrvcvghekusiahfxhlzclhbegdnvkzeoafodnqbtanfwixjzirnoaiqamjgkcapeopbzbgtxsjhqurbpbuduqjziznblrhxbydxsmtjdfeepntijqpkuwmqezkhnkwbvwgnkxmkyhlbfuwaslmjzlhocsgtoujabbexvxweigplmlewumcone";
	string ss = "ababcbab";
	cout << s.longestPalindrome(ss);
	//test();
	return 0;
}
