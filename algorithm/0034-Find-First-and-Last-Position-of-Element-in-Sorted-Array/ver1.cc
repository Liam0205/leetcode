class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        const size_t cut = binsearch(nums, 0, nums.size(), target, std::less<int>());
        if (-1 == cut) {
            return {-1, -1};
        } else {
            size_t first = cut;
            while (first != 0 and nums[first] == target) {
                --first;
            }
            if (nums[first] != target) {
                ++first;
            }
            size_t last = cut;
            while (last != nums.size() and nums[last] == target) {
                ++last;
            }
            --last;
            return {first, last};
        }
    }

private:
    template <typename Compare>
    size_t binsearch(const std::vector<int>& nums, const size_t first, const size_t last, const int target, Compare comp) {
        if (last - first < 1) {
            return -1;
        } else {
            const size_t cut = first + (last - first) / 2;
            if (comp(nums[cut], target)) {
                return binsearch(nums, cut + 1, last, target, comp);
            } else if (comp(target, nums[cut])) {
                return binsearch(nums, first, cut, target, comp);
            } else {
                return cut;
            }
        }
    }
};
