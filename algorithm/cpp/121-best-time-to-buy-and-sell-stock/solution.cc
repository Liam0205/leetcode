class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        size_t sz_length = prices.size();
        int int_local_max  = prices.at(1) - prices.at(0);
        int int_global_max = int_local_max;
        for (size_t i = 2; i != sz_length; ++i) {
            int_local_max  = prices.at(i) - prices.at(i - 1) + max(int_local_max, 0);
            int_global_max = max(int_local_max, int_global_max);
        }
        return max (int_global_max, 0);
    }
};
