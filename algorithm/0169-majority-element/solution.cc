class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        size_t len = nums.size();
        size_t limit = floor(len / 2);
        std::unordered_map<int, size_t> counter;
        for (size_t i = 0; i != len; ++i) {
            const int work = nums[i];
            if (counter.find(work) != counter.end()) {
                continue;
            } else {
                counter.insert({work, std::count((nums.begin() + i), nums.end(), work)});
            }
            if (counter[work] > limit) {
                return work;
            }
        }
    }
};
