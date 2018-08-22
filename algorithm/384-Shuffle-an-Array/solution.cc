class Solution {
public:
    Solution(const std::vector<int>& nums) : nums_(nums), rd_(), g_(rd_()) {}

    /** Resets the array to its original configuration and return it. */
    std::vector<int> reset() {
        return nums_;
    }

    /** Returns a random shuffling of the array. */
    std::vector<int> shuffle() const {
        std::vector<int> res(nums_);
        std::shuffle(res.begin(), res.end(), g_);
        return res;
    }

private:
    const std::vector<int> nums_;
    std::random_device rd_;
    mutable std::mt19937 g_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */

