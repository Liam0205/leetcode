class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    if (nums.size() == 0)
      return 0;
    else if (nums.size() == 1)
      return nums.at(0);

    int int_local_max = nums.at(0), int_global_max = nums.at(0);
    size_t sz_length = nums.size();
    for (size_t i = 1; i != sz_length; ++i) {
      int_local_max = max(int_local_max + nums.at(i), nums.at(i));
      int_global_max = max(int_local_max, int_global_max);
    }

    return int_global_max;
  }
};
