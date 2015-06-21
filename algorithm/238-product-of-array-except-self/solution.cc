class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> vec_int_prod = {1};
        int int_prod_reverse = 1;
        size_t sz_length = nums.size();
        for (size_t i = 0; i != sz_length - 1; ++i) {
            vec_int_prod.push_back(vec_int_prod.at(i) * nums.at(i));
        }
        for (size_t i = 0; i != sz_length; ++i) {
            vec_int_prod.at(sz_length - i - 1) *= int_prod_reverse;
            int_prod_reverse *= nums.at(sz_length - i - 1);
        }
        return vec_int_prod;
    }
};
