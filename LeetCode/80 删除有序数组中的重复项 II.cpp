class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0;
        for (int& n : nums) {
            if (left < 2 || n > nums[left - 2]) {
                nums[left] = n;
                left++;
            }
        }
        return left;
    }
};