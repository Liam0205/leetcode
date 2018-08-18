class Solution {
public:
    int missingNumber(vector<int>& nums) {
        size_t sz_length = nums.size();
        int int_total_sum = sz_length * (sz_length + 1) / 2;
        int int_sum = 0;
        for (size_t i = 0; i != sz_length; ++i)
            int_sum += nums.at(i);
        return int_total_sum - int_sum;
    }
};
