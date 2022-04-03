class Solution {
public:
	bool isPalindrome(int num) {
		if (num < 0) return false;
		int len = 0;
		int temp = num;
		while (temp!=0)
		{
			len++;
			temp /= 10;
		}
		temp = num;
		while (len>=2) {
			int i = temp % 10;
			int j = temp / (pow(10, len - 1));
			if (i != j)
				return false;
			temp -=  i * (pow(10, len-1));
			temp /= 10;
			len -= 2;
		}
		return true;
	}
};