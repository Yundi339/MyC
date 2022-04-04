class Solution {
private:
	const static regex pattern_scientific;
public:
	bool isNumber(string s) {
		return std::regex_match(s, pattern_scientific);
	}
};
const regex Solution::pattern_scientific("^[+-]?((\\d+\\.?\\d*)|(\\.\\d+))([Ee][+-]?\\d+)?$", regex::icase);
