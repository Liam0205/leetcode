class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        size_t left = 0, right = nums.size(), mid;
        while (left < right) {
            mid = (size_t) floor ((left + right) / 2);
            if (target > nums[mid])
                left  = mid + 1;
            else
                right = mid;
        }
        return (int) left;
    }
};
