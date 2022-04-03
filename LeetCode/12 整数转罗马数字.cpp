class Solution {
public:
	string intToRoman(int num) {
		const static unsigned int num_arr[] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
		const static string str_arr[] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
		const static size_t len = 13;
		string ans = "";
		for (size_t i = 0; i < len; i++)
		{
			int t = num / num_arr[i];
			if (t > 0) {
				do  {
					ans += str_arr[i];
				} while (--t > 0);
				num %= num_arr[i];
			}
		}
		return ans;
	}
};
