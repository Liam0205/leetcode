class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty()) return;
        size_t sz_zero_counter = 0;
        for (vector<int>::iterator iter_nums = nums.begin();
                iter_nums != nums.end();) {
            if (*iter_nums == 0) {
                iter_nums = nums.erase(iter_nums);
                ++sz_zero_counter;
            }
            else { ++iter_nums; }
        }
        for (size_t i = 0; i != sz_zero_counter; ++i) {
            nums.push_back(0);
        }
    }
};
