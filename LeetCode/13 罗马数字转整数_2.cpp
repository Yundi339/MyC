int replace(string& s, string key, unsigned int score) {
	int pos = 0;
	int count = 0;
	while ((pos = s.find(key)) != string::npos){
		s.replace(pos, key.size(), "");
		++count;
	}
	return count * score;
}

class Solution {
public:
	int romanToInt(string s) {
		const static unsigned int num_arr1[] = { 1000,500,100,50,10,5,1 };
		const static unsigned int num_arr2[] = { 900,400,90,40,9,4 };
		const static string str_arr1[] = { "M","D","C","L","X","V","I" };
		const static string str_arr2[] = { "CM","CD","XC","XL","IX","IV" };
		const static size_t len1 = 7;
		const static size_t len2 = 6;
		int ans = 0;
		for (size_t i = 0; i < len2; i++)
			ans += replace(s, str_arr2[i], num_arr2[i]);
		for (size_t i = 0; i < len1; i++)
			ans += replace(s, str_arr1[i], num_arr1[i]);
		return ans;
	}
};