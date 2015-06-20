class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        size_t sz_length = nums.size();
        int int_xor_res  = 0;
        for (size_t i = 0; i != sz_length; ++i) {
            int_xor_res ^= nums.at(i);
        }
        vector<int> vec_int_res = {0, 0};
        int int_last_one = (int_xor_res & (-int_xor_res));
        for (size_t i = 0; i != sz_length; ++i) {
            if ((int_last_one & nums.at(i)))
                vec_int_res[0] ^= nums.at(i);
            else
                vec_int_res[1] ^= nums.at(i);
        }
        return vec_int_res;
    }
};
