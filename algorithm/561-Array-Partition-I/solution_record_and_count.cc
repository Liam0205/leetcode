class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        std::vector<size_t> record(20001, 0);
        for (const auto i : nums) {
            ++(record[i + 10000]);
        }
        int res = 0;
        for (size_t i = 0, flag = 0; i != 20001; ++i) {
            const size_t count = record[i];
            size_t multi = count / 2;
            bool is_odd  = count & 0x01;
            if (is_odd and flag == 0) {
                ++multi;
            }
            res += multi * (i - 10000);
            if (is_odd) {
                flag ^= 1;  // flip
            }
        }
        return res;
    }
};
