class Solution {
public:
    int findMin(vector<int>& nums) {
        size_t sz_length = nums.size();
        for (size_t i = 1; i != sz_length; ++i) {
            if (nums.at(i) < nums.at(i - 1))
                return nums.at(i);
        }
        return nums.at(0);
    }
};
