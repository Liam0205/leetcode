class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), std::less<int>());
        int res = 0;
        const size_t sz = nums.size();
        for (size_t i = 0; i < sz; i += 2) {
            res += nums[i];
        }
        return res;
    }
};
