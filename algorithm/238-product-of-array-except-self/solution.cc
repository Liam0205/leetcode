class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        const size_t sz = nums.size();
        std::vector<int> res(sz, 1);
        for (size_t i = 1; i != sz; ++i) {
            const size_t j = i - 1;
            res[i] = res[j] * nums[j];
        }
        int tmp = 1;
        for (size_t i = 0; i != sz; ++i) {
            const size_t j = sz - 1 - i;
            res[j] *= tmp;
            tmp *= nums[j];
        }
        return res;
    }
};

