class Solution {
public:
    int majorityElement(vector<int>& nums) {
        size_t len = nums.size();
        size_t limit = floor(len / 2);
        map<int, size_t> counter;
        for (size_t i = 0; i != len; ++i) {
            if (counter.count(nums[i])) // we've test nums[i], and it's not the answer, so pass
                continue;
            else // test num[i], count the number of its appearance in the vector
                // nums.begin() + i, this is easy to understand and could boost the speed
                counter[nums[i]] = count((nums.begin() + i), nums.end(), nums[i]);
            if (counter[nums[i]] > limit)
                // if counter[nums[i]] > limit, return nums[i] immediately
                return nums[i];
        }
    }
};
