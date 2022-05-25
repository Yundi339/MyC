class Solution {
public:
    bool oneEditAway(const string& first,const string& second) {
        if (first.size() < second.size())
            return oneEditAway(second, first);
        int l1 = first.size();
        int l2 = second.size();
        int d = l1 - l2;
        if (d > 1) return false;
        if (first == second) return true;
        for (int i = 0, edit = 0; i < l1; ++i) {
            if (first[i] != second[i - d * edit] && ++edit > 1) {
                return false;
            }
        }
        return true;
    }
};