#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string res = "";
		int min_index = 0;
		for (int i = 1; i < strs.size();i++) {
			if (strs[i].length() < strs[min_index].length())
				min_index = i;
		}
		string s = strs[min_index];
		int max_length = s.length();
		while (max_length > 0) {
			string temp_s = s.substr(0, max_length);
			for (int i = 0; i < strs.size(); i++) {
				if (i == min_index)continue;
				if (strs[i].find(temp_s) != 0) {
					max_length--;
					break;
				}
			}
			if (max_length == temp_s.length())
				return temp_s;
		}
		return res;
	}
};
int main() 
{
	return 0;
}