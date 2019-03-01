class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = nums[0];
        size_t idx = 1, len = nums.size();
        for (; idx != len; ++idx) {
            // the result of a ^ a is 0
            // the result of a ^ 0 is a
            // these two equiv established for every integer a
            result = result ^ nums[idx];
        }
        return result;
    }
};
