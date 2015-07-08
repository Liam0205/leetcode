class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        size_t sz_length = prices.size();
        int int_sum = 0;
        for (size_t i = 1; i != sz_length; ++i)
            int_sum += max (0, prices.at(i) - prices.at(i - 1));
        return int_sum;
    }
};
